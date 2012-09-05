/* -*- c++ -*- */

#define HOWTO_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "howto_swig_doc.i"


%{
#include "howto_compare_vector_cci.h"
#include "howto_vector_source2.h"
%}

GR_SWIG_BLOCK_MAGIC(howto,compare_vector_cci);
%include "howto_compare_vector_cci.h"

GR_SWIG_BLOCK_MAGIC(howto,vector_source2);
%include "howto_vector_source2.h"

howto_compare_vector_cci_sptr howto_make_compare_vector_cci (const std::vector<unsigned char> &data, const std::vector<unsigned char> &preamble, unsigned short iteration_data_reg, unsigned short min_threshold_error, bool repeat);

howto_vector_source2_sptr howto_make_vector_source2 (const std::vector<unsigned char> &data, const std::vector<unsigned char> &preamble, bool with_preamble = false, bool repeat = false, int vlen = 1) throw(std::invalid_argument);

class howto_compare_vector_cci : public gr_block
{
public:
  bool is_same_vector_value const;
};

class howto_vector_source2 : public gr_sync_block {
 public:
  void rewind();
  void set_data(const std::vector<unsigned char> &data);
 private:
  gr_vector_source_b (const std::vector<unsigned char> &data, int vlen);
};