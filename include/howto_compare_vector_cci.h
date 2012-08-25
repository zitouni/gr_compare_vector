/* -*- c++ -*- */
/*
 * Copyright 2004 Free Software Foundation, Inc.
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
#ifndef INCLUDED_HOWTO_COMPARE_VECTOR_CCI_H
#define INCLUDED_HOWTO_COMPARE_VECTOR_CCI_H

#include <howto_api.h>
#include <gr_block.h>

class HOWTO_API howto_compare_vector_cci;
typedef boost::shared_ptr<howto_compare_vector_cci> howto_compare_vector_cci_sptr;

class howto_compare_vector_cci;

/*
 * We use boost::shared_ptr's instead of raw pointers for all access
 * to gr_blocks (and many other data structures).  The shared_ptr gets
 * us transparent reference counting, which greatly simplifies storage
 * management issues.  This is especially helpful in our hybrid
 * C++ / Python system.
 *
 * See http://www.boost.org/libs/smart_ptr/smart_ptr.htm
 *
 * As a convention, the _sptr suffix indicates a boost::shared_ptr
 */
typedef boost::shared_ptr<howto_compare_vector_cci> howto_compare_vector_cci_sptr;

/*!
 * \brief Return a shared_ptr to a new instance of howto_compare_vector_cci.
 *
 * To avoid accidental use of raw pointers, howto_compare_vector_cci's
 * constructor is private.  howto_make_compare_vector_cci is the public
 * interface for creating new instances.
 */
HOWTO_API howto_compare_vector_cci_sptr howto_make_compare_vector_cci (const std::vector<unsigned char> &data,  unsigned short size, bool repeat);

/*!
 * \brief square a stream of floats.
 * \ingroup block
 *
 * \sa howto_square2_ff for a version that subclasses gr_sync_block.
 */
class HOWTO_API howto_compare_vector_cci : public gr_block
{
std::vector<unsigned char>	d_data;
unsigned short  size;
bool			d_repeat;
bool is_same_vector(unsigned short d_shift_reg);
unsigned int min_threshold_error;


  // The friend declaration allows howto_make_compare_vector_cci to
  // access the private constructor.

  friend HOWTO_API howto_compare_vector_cci_sptr howto_make_compare_vector_cci (const std::vector<unsigned char> &data, unsigned short size, bool repeat);

private:
  /*!
   * \constructor of my block.
   */
  howto_compare_vector_cci (const std::vector<unsigned char> &data, unsigned short size, bool repeat);  	// private constructor
  unsigned short       		d_shift_reg;
  unsigned short			d_size;

 public:
  ~howto_compare_vector_cci ();	// public destructor

  // Where all the action really happens

  int general_work (int noutput_items,
		    gr_vector_int &ninput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);
};

#endif /* INCLUDED_HOWTO_compare_vector_cci_H */
