// Filename: decalTransition.h
// Created by:  drose (17Apr00)
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

#ifndef DECALTRANSITION_H
#define DECALTRANSITION_H

#include <pandabase.h>

#include <onOffTransition.h>

////////////////////////////////////////////////////////////////////
//       Class : DecalTransition
// Description : When this transition is in effect, the first GeomNode
//               encountered is rendered in a special mode, such that
//               all of its *children* (indeed, the whole subtree
//               beginning at the top GeomNode under the transition)
//               are rendered as decals of the GeomNode.
//
//               This means that the decal geometry (i.e. all geometry
//               in GeomNodes parented somewhere below the top
//               GeomNode) is assumed to be coplanar with the base
//               geometry, and will be rendered so that no z-fighting
//               will occur between it and the base geometry.
//
//               The render behavior is undefined if the decal
//               geometry is *not* coplanar with the base geometry.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA DecalTransition : public OnOffTransition {
PUBLISHED:
  INLINE DecalTransition();
  INLINE static DecalTransition off();

public:
  virtual NodeTransition *make_copy() const;
  virtual NodeTransition *make_initial() const;

  virtual bool has_sub_render() const;

public:
  static void register_with_read_factory(void);
  static TypedWritable *make_DecalTransition(const FactoryParams &params);

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
    register_type(_type_handle, "DecalTransition",
                  OnOffTransition::get_class_type());
  }

private:
  static TypeHandle _type_handle;
};

#include "decalTransition.I"

#endif
