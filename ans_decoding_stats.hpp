#pragma once

#include <cstdint>
#include <iostream>

struct ans_dec_stats {
    uint64_t num_no_decodes = 0;
    uint64_t postings_no_decodes = 0;
    uint64_t num_model_decodes = 0;
    uint64_t postings_model_decodes = 0;
    uint64_t model_usage[256] = { 0 };
    uint64_t model_frame_size[256] = { 0 };
    uint64_t ans_renorms_per_block[256] = { 0 };
    uint64_t min_renorm_interval[256];
    uint64_t final_state_bytes[8] = { 0 };
    ans_dec_stats()
    {
        for (size_t i = 0; i < 256; i++)
            min_renorm_interval[i] = 255;
    }
    static ans_dec_stats& doc_stats()
    {
        static std::unique_ptr<ans_dec_stats> s(new ans_dec_stats);
        return *s.get();
    }
    static ans_dec_stats& freq_stats()
    {
        static std::unique_ptr<ans_dec_stats> s(new ans_dec_stats);
        return *s.get();
    }
    static ans_dec_stats& stats(bool is_freq)
    {
        if (is_freq)
            return freq_stats();
        return doc_stats();
    }
    static void print_doc_stats()
    {
        std::cout << "DOCUMENT DECODING STATS" << std::endl;
        const auto& s = doc_stats();
        std::cout << "num_no_decodes = " << s.num_no_decodes << std::endl;
        std::cout << "postings_no_decodes = " << s.postings_no_decodes << std::endl;
        std::cout << "num_model_decodes = " << s.num_model_decodes << std::endl;
        std::cout << "postings_model_decodes = " << s.postings_model_decodes << std::endl;
        for (size_t i = 0; i < 256; i++) {
            if (s.model_usage[i] != 0) {
                std::cout << "model_id = " << i << " M = " << s.model_frame_size[i]
                          << " usage = " << s.model_usage[i]
                          << " percent = " << 100.0 * double(s.model_usage[i]) / double(s.num_model_decodes)
                          << " renorms = " << s.ans_renorms_per_block[i]
                          << " avg renorms = " << double(s.ans_renorms_per_block[i]) / double(s.model_usage[i])
                          << " min renorm interval = " << s.min_renorm_interval[i]
                          << std::endl;
            }
        }
        for (size_t i = 0; i < 8; i++) {
            std::cout << "final_state_bytes[" << i << "] = " << s.final_state_bytes[i]
                      << " percent = " << 100.0 * double(s.final_state_bytes[i]) / double(s.num_model_decodes)
                      << std::endl;
        }
    }
    static void print_freq_stats()
    {
        std::cout << "FREQ DECODING STATS" << std::endl;
        const auto& s = freq_stats();
        std::cout << "num_no_decodes = " << s.num_no_decodes << std::endl;
        std::cout << "postings_no_decodes = " << s.postings_no_decodes << std::endl;
        std::cout << "num_model_decodes = " << s.num_model_decodes << std::endl;
        std::cout << "postings_model_decodes = " << s.postings_model_decodes << std::endl;
        for (size_t i = 0; i < 256; i++) {
            if (s.model_usage[i] != 0) {
                std::cout << "model_id = " << i << " M = " << s.model_frame_size[i]
                          << " usage = " << s.model_usage[i]
                          << " percent = " << 100.0 * double(s.model_usage[i]) / double(s.num_model_decodes)
                          << " renorms = " << s.ans_renorms_per_block[i]
                          << " avg renorms = " << double(s.ans_renorms_per_block[i]) / double(s.model_usage[i])
                          << " min renorm interval = " << s.min_renorm_interval[i]
                          << std::endl;
            }
        }
        for (size_t i = 0; i < 8; i++) {
            std::cout << "final_state_bytes[" << i << "] = " << s.final_state_bytes[i]
                      << " percent = " << 100.0 * double(s.final_state_bytes[i]) / double(s.num_model_decodes)
                      << std::endl;
        }
    }
};
