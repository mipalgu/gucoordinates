/*
 * RelativeCoordinateTests.cc 
 * tests 
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

#include "GUWrapperTests.hpp"

namespace CGTEST {
    
    class RelativeCoordinateCPPTests: public GUWrapperTests<GU::RelativeCoordinate, gu_relative_coordinate> {

        protected:

        GU::RelativeCoordinate initial()
        {
            return GU::RelativeCoordinate(90, 100);
        }

        GU::RelativeCoordinate empty()
        {
            return GU::RelativeCoordinate(0, 0);
        }

        void change(GU::RelativeCoordinate &obj)
        {
            obj.set_direction(-90);
        }

        void cchange(gu_relative_coordinate &obj)
        {
            obj.direction = 40;
            obj.distance = 15;
        }

        gu_relative_coordinate cempty()
        {
            return empty();
        }

    };

    WRAPPER_TEST_Fs(RelativeCoordinate, gu_relative_coordinate)

    GETTER_TEST_F(RelativeCoordinate, CartesianCoordinate, rr_coord_to_cartesian_coord, cartesianCoordinate())
    GETTER_TEST_F(RelativeCoordinate, FieldCoordinate, rr_coord_to_field_coord, fieldCoordinate(30))
    GETTER_TEST_F(RelativeCoordinate, RelativeCoordinate, cartesian_coord_to_rr_coord_from_source, relativeCoordinateTo(GU::RelativeCoordinate(30, 120)))

    GETTER_IM_TEST_NAME_F(RelativeCoordinate, cameraCoordinate, CameraCoordinate, px_coord_to_cam_coord, PercentCoordinate, rr_coord_to_pct_coord, cameraCoordinate(nao, GU_NAO_V5_BOTTOM_CAMERA_INDEX, 1920, 1080))
    GETTER_IM_TEST_NAME_F(RelativeCoordinate, pixelCoordinate, PixelCoordinate, pct_coord_to_px_coord, PercentCoordinate, rr_coord_to_pct_coord, pixelCoordinate(nao, GU_NAO_V5_BOTTOM_CAMERA_INDEX, 1920, 1080))
    GETTER_TEST_NAME_F(RelativeCoordinate, percentCoordinate, PercentCoordinate, rr_coord_to_pct_coord, percentCoordinate(nao, GU_NAO_V5_BOTTOM_CAMERA_INDEX))

    GETTER_IM_TEST_NAME_F(RelativeCoordinate, clampedCameraCoordinate, CameraCoordinate, px_coord_to_cam_coord, PercentCoordinate, clamped_rr_coord_to_pct_coord, clampedCameraCoordinate(nao, GU_NAO_V5_BOTTOM_CAMERA_INDEX, 1920, 1080))
    GETTER_IM_TEST_NAME_F(RelativeCoordinate, clampedPixelCoordinate, PixelCoordinate, pct_coord_to_px_coord, PercentCoordinate, clamped_rr_coord_to_pct_coord, clampedPixelCoordinate(nao, GU_NAO_V5_BOTTOM_CAMERA_INDEX, 1920, 1080))
    GETTER_TEST_NAME_F(RelativeCoordinate, clampedPercentCoordinate, PercentCoordinate, clamped_rr_coord_to_pct_coord, clampedPercentCoordinate(nao, GU_NAO_V5_BOTTOM_CAMERA_INDEX))

    TEST_F(RelativeCoordinateCPPTests, GettersSetters) {
        GU::RelativeCoordinate coord = GU::RelativeCoordinate(90.0, 1000);
        ASSERT_EQ(coord.direction(), 90.0);
        coord.set_direction(-90.0);
        ASSERT_EQ(coord.direction(), -90.0);
        ASSERT_EQ(coord.distance(), 1000);
        coord.set_distance(100);
        ASSERT_EQ(coord.distance(), 100);
    }

}  // namespace
