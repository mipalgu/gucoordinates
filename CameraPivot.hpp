/*
 * CameraPivot.hpp 
 * gucoordinates 
 *
 * Created by Callum McColl on 20/06/2020.
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

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "camera_pivot.h"
#include "Camera.hpp"

#include <cstdlib>

namespace GU {

    struct CameraPivot: public gu_camera_pivot {

        CameraPivot();
        CameraPivot(degrees_f, degrees_f, const gu_camera[GU_CAMERA_PIVOT_NUM_CAMERAS], const centimetres_f[GU_CAMERA_PIVOT_NUM_CAMERAS], int);
        CameraPivot(const CameraPivot& other);
        CameraPivot(const gu_camera_pivot& other);
#if __cplusplus >= 201103L
        CameraPivot(CameraPivot&& other);
#endif
        ~CameraPivot();
        CameraPivot& operator=(const CameraPivot& other);
        CameraPivot& operator=(const gu_camera_pivot& other);
#if __cplusplus >= 201103L
        CameraPivot& operator=(CameraPivot&& other);
#endif

        degrees_f headPitch() const;
        void set_headPitch(const degrees_f);

        degrees_f headYaw() const;
        void set_headYaw(const degrees_f);

        const gu_camera * cameras() const;
        void set_cameras(const gu_camera[GU_CAMERA_PIVOT_NUM_CAMERAS]);

        Camera camera(const int) const;
        void set_camera(const int, const Camera);

        const centimetres_f * cameraHeightOffsets() const;
        void set_cameraHeightOffsets(const centimetres_f[GU_CAMERA_PIVOT_NUM_CAMERAS]);

        centimetres_f cameraHeightOffset(const int) const;
        void set_cameraHeightOffset(const int, const centimetres_f);

        int numCameras() const;
        void set_numCameras(const int);

        bool operator ==(const CameraPivot &other) const;
        bool operator !=(const CameraPivot &other) const;
        bool operator ==(const gu_camera_pivot &other) const;
        bool operator !=(const gu_camera_pivot &other) const;

    };

}

#endif  /* ROBOT_HPP */