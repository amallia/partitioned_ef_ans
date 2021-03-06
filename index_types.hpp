#pragma once

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/stringize.hpp>

#include "ans_block_freq_index.hpp"
#include "binary_freq_collection.hpp"
#include "block_codecs.hpp"
#include "block_freq_index.hpp"
#include "freq_index.hpp"
#include "partitioned_sequence.hpp"
#include "positive_sequence.hpp"
#include "uniform_partitioned_sequence.hpp"

namespace quasi_succinct {

typedef freq_index<compact_elias_fano,
    positive_sequence<strict_elias_fano>>
    ef_index;

typedef freq_index<indexed_sequence,
    positive_sequence<>>
    single_index;

typedef freq_index<uniform_partitioned_sequence<>,
    positive_sequence<uniform_partitioned_sequence<strict_sequence>>>
    uniform_index;

typedef freq_index<partitioned_sequence<>,
    positive_sequence<partitioned_sequence<strict_sequence>>>
    opt_index;

typedef block_freq_index<quasi_succinct::optpfor_block> block_optpfor_index;

typedef block_freq_index<quasi_succinct::varint_G8IU_block> block_varint_index;

typedef block_freq_index<quasi_succinct::interpolative_block> block_interpolative_index;

typedef block_freq_index<quasi_succinct::u32_block> block_u32_index;

typedef block_freq_index<quasi_succinct::vbyte_block> block_vbyte_index;

typedef block_freq_index<quasi_succinct::simple16_block> block_simple16_index;

typedef ans_block_freq_index<quasi_succinct::ans_packed_model<model_max_1d>> block_anspacked_index;
// typedef ans_block_freq_index<quasi_succinct::ans_packed_model<model_minmax_2d>> block_anspackedminmax_index;
// typedef ans_block_freq_index<quasi_succinct::ans_packed_model<model_med90p_2d>> block_anspackedmed90p_index;

typedef ans_block_freq_index<quasi_succinct::ans_msb_model<msb_model_max_1d>> block_ansmsb_index;
typedef ans_block_freq_index<quasi_succinct::ans_msb_model<msb_model_minmax_2d>> block_ansmsbminmax_index;
typedef ans_block_freq_index<quasi_succinct::ans_msb_model<msb_model_med90p_2d>> block_ansmsbmed90p_index;
typedef ans_block_freq_index<quasi_succinct::ans_msb_model<msb_model_med90p_2d_merged>> block_ansmsbmed90pmerged_index;
typedef ans_block_freq_index<quasi_succinct::ans_msb_model<msb_model_medmax_2d_merged>> block_ansmsbmedmaxmerged_index;
}

#define QS_INDEX_TYPES (ef)(single)(uniform)(opt)(block_optpfor)(block_varint)(block_interpolative)(block_u32)(block_vbyte)(block_simple16)(block_anspacked)(block_ansmsb)(block_ansmsbminmax)(block_ansmsbmed90p)(block_ansmsbmed90pmerged)(block_ansmsbmedmaxmerged)
