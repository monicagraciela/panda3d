// Filename: showBase.h
// Created by:  shochet (02Feb00)
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

#ifndef SHOWBASE_H
#define SHOWBASE_H

#include <directbase.h>

#include <eventHandler.h>
#include <graphicsPipe.h>
#include <graphicsWindow.h>
#include <animControl.h>
#include <nodeRelation.h>
#include <pointerTo.h>
#include <nodePath.h>
#include <dconfig.h>
#include <dSearchPath.h>
#include <chancfg.h>

ConfigureDecl(config_showbase, EXPCL_DIRECT, EXPTP_DIRECT);
typedef Config::Config<ConfigureGetConfig_config_showbase> ConfigShowbase;

class CollisionTraverser;
class Camera;

BEGIN_PUBLISH

EXPCL_DIRECT DSearchPath &get_particle_path();

EXPCL_DIRECT PT(GraphicsPipe) make_graphics_pipe();
EXPCL_DIRECT ChanConfig
  make_graphics_window(GraphicsPipe *pipe,
                       NodeRelation *render_arc);

EXPCL_DIRECT NodePath setup_panda_2d(GraphicsWindow *win, const string &name);
EXPCL_DIRECT void add_render_layer(GraphicsWindow *win, Node *render_top,
                                   Camera *camera);

EXPCL_DIRECT void toggle_wireframe(NodeRelation *render_arc);
EXPCL_DIRECT void toggle_texture(NodeRelation *render_arc);
EXPCL_DIRECT void toggle_backface(NodeRelation *render_arc);

EXPCL_DIRECT void take_snapshot(GraphicsWindow *win, const string &name);

EXPCL_DIRECT ConfigShowbase &get_config_showbase();

END_PUBLISH

#endif
