/* -*- c++ -*- */
/*
 * Copyright 2004,2010 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

/*
 * config.h is generated by configure.  It contains the results
 * of probing for features, options etc.  It should be the first
 * file included in your .cc file.
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <howto_vector_source2.h>
#include <gr_io_signature.h>


#include <stdio.h>

/*
 * Create a new instance of howto_vector_source2 and return
 * a boost shared_ptr.  This is effectively the public constructor.
 */
howto_vector_source2_sptr
howto_make_vector_source2 (const std::vector<unsigned char> &data, const std::vector<unsigned char> &preamble, bool with_preamble, bool repeat, int vlen)
{
  return gnuradio::get_initial_sptr(new howto_vector_source2 (data, preamble, with_preamble, repeat, vlen));
}

/*
 * Specify constraints on number of input and output streams.
 * This info is used to construct the input and output signatures
 * (2nd & 3rd args to gr_block's constructor).  The input and
 * output signatures are used by the runtime system to
 * check that a valid number and type of inputs and outputs
 * are connected to this block.  In this case, we accept
 * only 1 input and 1 output.
 */
static const int MIN_IN = 0;	// mininum number of input streams
static const int MAX_IN = 0;	// maximum number of input streams
static const int MIN_OUT = 1;	// minimum number of output streams
static const int MAX_OUT = 1;	// maximum number of output streams

/*
 * The private constructor
 */
howto_vector_source2::howto_vector_source2 (const std::vector<unsigned char> &data, const std::vector<unsigned char> &preamble, bool with_preamble, bool repeat, int vlen)
  : gr_sync_block ("vector_source2",
		   gr_make_io_signature (MIN_IN, MAX_IN, 0),
		   gr_make_io_signature (MIN_OUT, MAX_OUT, sizeof (unsigned char) * vlen)),
	d_data (data),
	d_preamble (preamble),
	d_with_preamble (with_preamble),

	d_repeat (repeat),
	d_offset (0),
	d_offset_preamble (0),
	d_vlen (vlen)
{
	if ((data.size() % vlen) != 0)
       throw std::invalid_argument("data length must be a multiple of vlen");
  // nothing else required in this example
}

/*
 * Our virtual destructor.
 */
howto_vector_source2::~howto_vector_source2 ()
{
  // nothing else required in this example
}

int
howto_vector_source2::work (int noutput_items,
			gr_vector_const_void_star &input_items,
			gr_vector_void_star &output_items)
{
  unsigned char *optr = (unsigned char *) output_items[0];
  unsigned int size;
  unsigned int preamble_offset = 0, data_offset = 0;


  if (d_with_preamble)
		size = d_data.size () + d_preamble.size();
  else
		size = d_data.size ();

  //printf("size of vector is : %d\n", size);

  if (d_repeat){

    if (size == 0)
      return -1;

    for (int i = 0; i < noutput_items*d_vlen; i++){
      if (d_with_preamble){
    	  if (preamble_offset <d_preamble.size()){
    		  //printf("d_preamble[%d] : %d \n", preamble_offset, d_preamble[preamble_offset]);
    		  optr[i] = d_preamble[preamble_offset++];
    	      //memcpy(&out[i], &d_symbol_table[(unsigned int)(in[i/2]&0xF)], sizeof(unsigned int));
    		  //memcpy(&optr[i], &d_preamble[preamble_offset++], sizeof(unsigned char));
    	  }else{
    		  if(data_offset < d_data.size()){
    		   	  //printf("d_data[%d] : %d \n", data_offset, d_data[data_offset]);
    			  optr[i] = d_data[data_offset++];
    			  //memcpy(&optr[i], &d_data[data_offset++], sizeof(unsigned char));
    		  }

    	  }
      }else{
    	  //printf("d_data[%d] : %d \n", data_offset, d_data[data_offset]);
    	  optr[i] = d_data[data_offset ++];
      }

      if ((data_offset + preamble_offset) == size){
    	  data_offset = 0;
    	  preamble_offset = 0;
    	  //exit(1);
      }
    }
    return noutput_items;
  }

  else {

    if (d_offset >= d_data.size ())
      return -1;			// Done!

    unsigned n = std::min ((unsigned) size - d_offset,
			   (unsigned) noutput_items*d_vlen);
    for (unsigned i = 0; i < n; i++){
        if (d_with_preamble){
      	  if (preamble_offset <d_preamble.size()){
      		  optr[i] = d_preamble[preamble_offset++];
      		  d_offset = preamble_offset;
      	  }
      	  else{
      		  if(data_offset < d_data.size()){
      			  optr[i] = d_data[data_offset];
      			  d_offset = data_offset;
      		  }
      	  }
        }else
      	  optr[i] = d_data[d_offset++];
    }
    d_offset += n;
    return n/d_vlen;
  }
}

