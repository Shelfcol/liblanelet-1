// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// Copyright (c) 2018, FZI Forschungszentrum Informatik
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions
//    and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of
//    conditions and the following disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be used to
//    endorse or promote products derived from this software without specific prior written
//    permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
// FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
// WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
*
* \author  Tim Pollert <pollert@fzi.de>
* \date    2016-05-23
*
*/
//----------------------------------------------------------------------

#include "EventRegion.hpp"
#include "Polygon.hpp"

namespace LLet
{

EventRegion::EventRegion(const std::vector<point_with_id_t>& vertices)
{
  _vertices = vertices;
  assert(isValid());
  _polygon.reset(new Polygon(*this));
}

EventRegion::~EventRegion ()
{
}

bool EventRegion::isValid()
{
  return (_vertices.size() >= 3) && (_vertices.front().get<2>() == _vertices.back().get<2>());
}

const int64_t EventRegion::getId() const
{
  return _id;
}

void EventRegion::setId(const int64_t value)
{
  _id = value;
}

const EventRegion::Type EventRegion::getType() const
{
  return _event_type;
}

void EventRegion::setType(const Type value)
{
  _event_type = value;
}

const std::vector< point_with_id_t >& EventRegion::getVertices() const
{
  return _vertices;
}

bool EventRegion::covers_point(const point_with_id_t& query) const
{
  return _polygon->pointInsidePolygon(query);
}


} // namespace
