// Filename: geomBinTransition.h
// Created by:  drose (07Apr00)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://www.panda3d.org/license.txt .
//
// To contact the maintainers of this program write to
// panda3d@yahoogroups.com .
//
////////////////////////////////////////////////////////////////////

#ifndef GEOMBINTRANSITION_H
#define GEOMBINTRANSITION_H

#include <pandabase.h>

#include <onOffTransition.h>
#include "geomBin.h"

////////////////////////////////////////////////////////////////////
//       Class : GeomBinTransition
// Description :
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA GeomBinTransition : public OnOffTransition {
PUBLISHED:
  INLINE GeomBinTransition();
  INLINE GeomBinTransition(const string &bin, int draw_order);
  INLINE static GeomBinTransition off();

  INLINE void set_on(const string &bin, int draw_order);
  INLINE const string &get_bin() const;
  INLINE int get_draw_order() const;

public:
  virtual NodeTransition *make_copy() const;
  virtual NodeTransition *make_initial() const;

protected:
  virtual void set_value_from(const OnOffTransition *other);
  virtual int compare_values(const OnOffTransition *other) const;
  virtual void output_value(ostream &out) const;
  virtual void write_value(ostream &out, int indent_level) const;

  string _value;
  int _draw_order;

public:
  static void register_with_read_factory();
  virtual void write_datagram(BamWriter* manager, Datagram &me);

  static TypedWritable *make_GeomBinTransition(const FactoryParams &params);

protected:
  void fillin(DatagramIterator& scan, BamReader* manager);

public:
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    OnOffTransition::init_type();
    register_type(_type_handle, "GeomBinTransition",
                  OnOffTransition::get_class_type());
  }

private:
  static TypeHandle _type_handle;
};

#include "geomBinTransition.I"

#endif
