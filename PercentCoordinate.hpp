/*
 * PercentCoordinate.hpp 
 * guvision_utils 
 *
 * Created by Callum McColl on 19/06/2020.
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
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * -----------------------------------------------------------------------
 * This program is free software; you can redistribute it and/or
 * modify it under the above terms or under the terms of the GNU
 * General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/
 * or write to the Free Software Foundation, Inc., 51 Franklin Street,
 * Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef PERCENTCOORDINATE_HPP
#define PERCENTCOORDINATE_HPP

#include "percent_coordinate.h"
#include "RelativeCoordinate.hpp"
#include "PixelCoordinate.hpp"
#include "CameraCoordinate.hpp"
#include "Robot.hpp"

#include <cstdlib>

#if __cplusplus >= 201703L
#include <optional>
#endif

namespace GU {

    struct CameraCoordinate; // Forward Declaration.
    struct PixelCoordinate; // Forward Declaration.
    struct RelativeCoordinate; // Forward Declaration.

    struct PercentCoordinate: public gu_percent_coordinate {

        PercentCoordinate();
        PercentCoordinate(percent_f, percent_f);
        PercentCoordinate(const PercentCoordinate& other);
        PercentCoordinate(const gu_percent_coordinate& other);
#if __cplusplus >= 201103L
        PercentCoordinate(PercentCoordinate&& other);
#endif
        ~PercentCoordinate();
        PercentCoordinate& operator=(const PercentCoordinate& other);
        PercentCoordinate& operator=(const gu_percent_coordinate& other);
#if __cplusplus >= 201103L
        PercentCoordinate& operator=(PercentCoordinate&& other);
#endif

        CameraCoordinate cameraCoordinate(const pixels_u, const pixels_u) const;
        PixelCoordinate pixelCoordinate(const pixels_u, const pixels_u) const;
        bool relativeCoordinate(const GU::Robot &, const int, GU::RelativeCoordinate &) const;

#if __cplusplus >= 201703L
        std::optional<RelativeCoordinate> relativeCoordinate(const GU::Robot &, const int) const;
#endif

        percent_f x() const;
        void set_x(const percent_f);

        percent_f y() const;
        void set_y(const percent_f);

        bool operator ==(const PercentCoordinate &other) const;
        bool operator !=(const PercentCoordinate &other) const;
        bool operator ==(const gu_percent_coordinate &other) const;
        bool operator !=(const gu_percent_coordinate &other) const;

    };

}

#endif  /* PERCENTCOORDINATE_HPP */
