// -*- mode: c++; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 78 -*-
//
// OpenVRML
//
// Copyright 2006, 2007, 2008, 2009  Braden McDaniel
//
// This library is free software; you can redistribute it and/or modify it
// under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 3 of the License, or (at your
// option) any later version.
//
// This library is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
// License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library; if not, see <http://www.gnu.org/licenses/>.
//

# include "multi_texture_coordinate.h"
# include <openvrml/node_impl_util.h>
# include <boost/array.hpp>

# ifdef HAVE_CONFIG_H
#   include <config.h>
# endif

using namespace openvrml;
using namespace openvrml::node_impl_util;
using namespace std;

namespace {

    class OPENVRML_LOCAL multi_texture_coordinate_node :
        public abstract_node<multi_texture_coordinate_node> {

        friend
        class openvrml_node_x3d_texturing::multi_texture_coordinate_metatype;

        exposedfield<mfnode> tex_coord_;

    public:
        multi_texture_coordinate_node(
            const node_type & type,
            const boost::shared_ptr<openvrml::scope> & scope);
        virtual ~multi_texture_coordinate_node() OPENVRML_NOTHROW;
    };


    /**
     * @class multi_texture_coordinate_node
     *
     * @brief Represents MultiTextureCoordinate node instances.
     */

    /**
     * @var multi_texture_coordinate_node::multi_texture_coordinate_metatype
     *
     * @brief Class object for MultiTextureCoordinate nodes.
     */

    /**
     * @var multi_texture_coordinate_node::tex_coord_
     *
     * @brief tex_coord exposedField
     */


    /**
     * @brief Construct.
     *
     * @param type  the node_type associated with this node.
     * @param scope the scope to which the node belongs.
     */
    multi_texture_coordinate_node::
    multi_texture_coordinate_node(
        const node_type & type,
        const boost::shared_ptr<openvrml::scope> & scope):
        node(type, scope),
        abstract_node<self_t>(type, scope),
        tex_coord_(*this)
    {}

    /**
     * @brief Destroy.
     */
    multi_texture_coordinate_node::~multi_texture_coordinate_node()
        OPENVRML_NOTHROW
    {}
}


/**
 * @brief @c node_metatype identifier.
 */
const char * const
openvrml_node_x3d_texturing::multi_texture_coordinate_metatype::id =
    "urn:X-openvrml:node:MultiTextureCoordinate";

/**
 * @brief Construct.
 *
 * @param browser the @c browser associated with this
 *                @c multi_texture_coordinate_metatype.
 */
openvrml_node_x3d_texturing::multi_texture_coordinate_metatype::
multi_texture_coordinate_metatype(openvrml::browser & browser):
    node_metatype(multi_texture_coordinate_metatype::id, browser)
{}

/**
 * @brief Destroy.
 */
openvrml_node_x3d_texturing::multi_texture_coordinate_metatype::
~multi_texture_coordinate_metatype()
    OPENVRML_NOTHROW
{}

# define MULTI_TEXTURE_COORDINATE_INTERFACE_SEQ         \
    ((exposedfield, sfnode, "metadata", metadata))      \
    ((exposedfield, mfnode, "texCoord", tex_coord_))

OPENVRML_NODE_IMPL_UTIL_DEFINE_DO_CREATE_TYPE(
    openvrml_node_x3d_texturing,
    multi_texture_coordinate_metatype,
    multi_texture_coordinate_node,
    MULTI_TEXTURE_COORDINATE_INTERFACE_SEQ)
