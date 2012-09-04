/* -*- c++ -*- */

#define HOWTO_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "howto_swig_doc.i"


%{
#include "howto_compare_vector_cci.h"
#include "howto_square2_ff.h"
%}

GR_SWIG_BLOCK_MAGIC(howto,compare_vector_cci);
%include "howto_compare_vector_cci.h"

GR_SWIG_BLOCK_MAGIC(howto,square2_ff);
%include "howto_square2_ff.h"

howto_compare_vector_cci_sptr howto_make_compare_vector_cci (const std::vector<unsigned char> &data, const std::vector<unsigned char> &preamble, unsigned short iteration_data_reg, unsigned short min_threshold_error, bool repeat);


class howto_compare_vector_cci : public gr_block
{
public:
  bool is_same_vector_value const;
};