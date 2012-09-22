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
#ifndef INCLUDED_HOWTO_VECTOR_SOURCE2_H
#define INCLUDED_HOWTO_VECTOR_SOURCE2_H

#include <howto_api.h>
#include <gr_sync_block.h>

class howto_vector_source2;

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
typedef boost::shared_ptr<howto_vector_source2> howto_vector_source2_sptr;

/*!
 * \brief Return a shared_ptr to a new instance of howto_vector_source2.
 *
 * To avoid accidental use of raw pointers, howto_vector_source2's
 * constructor is private.  howto_make_vector_source2 is the public
 * interface for creating new instances.
 */
HOWTO_API howto_vector_source2_sptr howto_make_vector_source2 (const std::vector<unsigned char> &data,const std::vector<unsigned char> &preamble, bool with_preamble, bool repeat = false, int vlen = 1);

/*!
 * \brief square2 a stream of floats.
 * \ingroup block
 *
 * This uses the preferred technique: subclassing gr_sync_block.
 */
class HOWTO_API howto_vector_source2 : public gr_sync_block
{
private:
  // The friend declaration allows howto_make_vector_source2 to
  // access the private constructor.

  friend HOWTO_API howto_vector_source2_sptr howto_make_vector_source2 (const std::vector<unsigned char> &data, const std::vector<unsigned char> &preamble, bool with_preamble, bool repeat, int vlen);

  std::vector<unsigned char>	d_data;
  std::vector<unsigned char>  	d_preamble;

  bool 							d_with_preamble;
  bool							d_repeat;
  unsigned int					d_offset;
  unsigned int 					d_offset_preamble;
  int							d_vlen;

  howto_vector_source2 (const std::vector<unsigned char> &data, const std::vector<unsigned char> &preamble, bool with_preamble, bool repeat, int vlen);  	// private constructor

 public:
  ~howto_vector_source2 ();	// public destructor

  // Where all the action really happens
  void rewind() {d_offset=0;}

  int work (int noutput_items,
	    gr_vector_const_void_star &input_items,
	    gr_vector_void_star &output_items);

  void set_data(const std::vector<unsigned char> &data){ d_data = data; rewind(); }
};

#endif /* INCLUDED_HOWTO_VECTOR_SOURCE2_H */
