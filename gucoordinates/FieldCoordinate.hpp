/*
 * FieldCoordinate.hpp 
 * gucoordinates 
 *
 * Created by Callum McColl on 21/06/2020.
 * Copyright © 2020 Callum McColl. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *
 *        This product includes software developed by Callum McColl.
 *
 * 4. Neither the name of the author nor the names of contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES NOEXCEPT; LOSS OF USE, DATA, OR
 * PROFITS NOEXCEPT; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software NOEXCEPT; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation NOEXCEPT;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY NOEXCEPT; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program NOEXCEPT; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef FIELDCOORDINATE_HPP
#define FIELDCOORDINATE_HPP

#include "field_coordinate.h"

#include <cstdlib>
#include <guunits/guunits.h>
#include "CameraCoordinate.hpp"
#include "PixelCoordinate.hpp"
#include "PercentCoordinate.hpp"
#include "RelativeCoordinate.hpp"
#include "CartesianCoordinate.hpp"
#include "CameraPivot.hpp"

#include "OptionalCameraCoordinate.hpp"
#include "OptionalPixelCoordinate.hpp"
#include "OptionalPercentCoordinate.hpp"
#include "OptionalRelativeCoordinate.hpp"
#include "OptionalCartesianCoordinate.hpp"
#include "OptionalFieldCoordinate.hpp"

#if __cplusplus >= 201703L
#include <optional>
#endif

#include <gu_util.h>

namespace GU {

    struct CameraCoordinate;
    struct PixelCoordinate;
    struct PercentCoordinate;
    struct RelativeCoordinate;
    struct CartesianCoordinate;

    struct FieldCoordinate: public gu_field_coordinate {

        FieldCoordinate() NOEXCEPT;
        FieldCoordinate(CartesianCoordinate, degrees_t) NOEXCEPT;
        FieldCoordinate(const FieldCoordinate& other) NOEXCEPT;
        FieldCoordinate(const gu_field_coordinate& other) NOEXCEPT;
#if __cplusplus >= 201103L
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"
        FieldCoordinate(FieldCoordinate&& other) NOEXCEPT;
        FieldCoordinate(gu_field_coordinate&& other) NOEXCEPT;
#pragma clang diagnostic pop
#endif
        ~FieldCoordinate() NOEXCEPT;
        FieldCoordinate& operator=(const FieldCoordinate& other) NOEXCEPT;
        FieldCoordinate& operator=(const gu_field_coordinate& other) NOEXCEPT;
#if __cplusplus >= 201103L
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++98-compat"
        FieldCoordinate& operator=(FieldCoordinate&& other) NOEXCEPT;
        FieldCoordinate& operator=(gu_field_coordinate&& other) NOEXCEPT;
#pragma clang diagnostic pop
#endif

        CartesianCoordinate cartesianCoordinateAt(const GU::RelativeCoordinate &) const NOEXCEPT;
        FieldCoordinate fieldCoordinateAt(const GU::RelativeCoordinate &, const degrees_t) const NOEXCEPT;
        RelativeCoordinate relativeCoordinateTo(const GU::CartesianCoordinate &) const NOEXCEPT;
        RelativeCoordinate relativeCoordinateTo(const GU::FieldCoordinate &) const NOEXCEPT;

        CartesianCoordinate cartesianCoordinateAt(const GU::CameraCoordinate &, const GU::CameraPivot &, const int) const NOEXCEPT;
        CartesianCoordinate cartesianCoordinateAt(const GU::PixelCoordinate &, const GU::CameraPivot &, const int) const NOEXCEPT;
        CartesianCoordinate cartesianCoordinateAt(const GU::PercentCoordinate &, const GU::CameraPivot &, const int) const NOEXCEPT;
        FieldCoordinate fieldCoordinateAt(const GU::CameraCoordinate &, const GU::CameraPivot &, const int, const degrees_t) const NOEXCEPT;
        FieldCoordinate fieldCoordinateAt(const GU::PixelCoordinate &, const GU::CameraPivot &, const int, const degrees_t) const NOEXCEPT;
        FieldCoordinate fieldCoordinateAt(const GU::PercentCoordinate &, const GU::CameraPivot &, const int, const degrees_t) const NOEXCEPT;

        CameraCoordinate cameraCoordinateTo(const GU::CartesianCoordinate &, const GU::CameraPivot &, const int, const pixels_u, const pixels_u) const NOEXCEPT;
        CameraCoordinate cameraCoordinateTo(const GU::FieldCoordinate &, const GU::CameraPivot &, const int, const pixels_u, const pixels_u) const NOEXCEPT;
        PixelCoordinate pixelCoordinateTo(const GU::CartesianCoordinate &, const GU::CameraPivot &, const int, const pixels_u, const pixels_u) const NOEXCEPT;
        PixelCoordinate pixelCoordinateTo(const GU::FieldCoordinate &, const GU::CameraPivot &, const int, const pixels_u, const pixels_u) const NOEXCEPT;
        PercentCoordinate percentCoordinateTo(const GU::CartesianCoordinate &, const GU::CameraPivot &, const int) const NOEXCEPT;
        PercentCoordinate percentCoordinateTo(const GU::FieldCoordinate &, const GU::CameraPivot &, const int) const NOEXCEPT;

        CameraCoordinate clampedCameraCoordinateTo(const GU::CartesianCoordinate &, const GU::CameraPivot &, const int, const pixels_u, const pixels_u) const NOEXCEPT;
        CameraCoordinate clampedCameraCoordinateTo(const GU::FieldCoordinate &, const GU::CameraPivot &, const int, const pixels_u, const pixels_u) const NOEXCEPT;
        PixelCoordinate clampedPixelCoordinateTo(const GU::CartesianCoordinate &, const GU::CameraPivot &, const int, const pixels_u, const pixels_u) const NOEXCEPT;
        PixelCoordinate clampedPixelCoordinateTo(const GU::FieldCoordinate &, const GU::CameraPivot &, const int, const pixels_u, const pixels_u) const NOEXCEPT;
        PercentCoordinate clampedPercentCoordinateTo(const GU::CartesianCoordinate &, const GU::CameraPivot &, const int) const NOEXCEPT;
        PercentCoordinate clampedPercentCoordinateTo(const GU::FieldCoordinate &, const GU::CameraPivot &, const int) const NOEXCEPT;

        CartesianCoordinate position() const NOEXCEPT;
        void set_position(const CartesianCoordinate) NOEXCEPT;

        degrees_t heading() const NOEXCEPT;
        void set_heading(const degrees_t) NOEXCEPT;

        bool operator ==(const FieldCoordinate &other) const NOEXCEPT;
        bool operator !=(const FieldCoordinate &other) const NOEXCEPT;
        bool operator ==(const gu_field_coordinate &other) const NOEXCEPT;
        bool operator !=(const gu_field_coordinate &other) const NOEXCEPT;

    };

}

#endif  /* FIELDCOORDINATE_HPP */
