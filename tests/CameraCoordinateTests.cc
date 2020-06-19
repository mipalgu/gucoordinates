/*
 * CameraCoordinateTests.cc 
 * tests 
 *
 * Created by Callum McColl on 18/06/2020.
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma clang diagnostic ignored "-Wshift-sign-overflow"
#pragma clang diagnostic ignored "-Wused-but-marked-unused"
#pragma clang diagnostic ignored "-Wdeprecated"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wsign-compare"
#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#pragma clang diagnostic ignored "-Wfloat-equal"

#include <gtest/gtest.h>
#include "fff.h"

#include "../GUCoordinates.hpp"
#include "conversion_fakes.h"

namespace CGTEST {

    class CameraCoordinateCPPTests: public ::testing::Test {
    protected:
        
        virtual void SetUp() {
            CONVERSION_FAKES(RESET_FAKE);
            FFF_RESET_HISTORY();
        }
        
        virtual void TearDown() {
            CONVERSION_FAKES(RESET_FAKE);
            FFF_RESET_HISTORY();
        }

    };

    TEST_F(CameraCoordinateCPPTests, RO5)
    {
        GU::CameraCoordinate coord = GU::CameraCoordinate(1, 2, 3, 4);
        GU::CameraCoordinate coord2 = GU::CameraCoordinate(coord);
        ASSERT_EQ(coord, coord2);
        GU::CameraCoordinate coord3 = coord2;
        ASSERT_EQ(coord, coord3);
        coord.set_x(0);
        ASSERT_NE(coord, coord3);
        ASSERT_EQ(coord2, coord3);
#if __cplusplus >= 199711L
        GU::CameraCoordinate coord4 = std::move(coord2);
        ASSERT_NE(coord4, coord2);
        ASSERT_EQ(coord4, coord3);
        ASSERT_EQ(coord2.x(), 0);
        ASSERT_EQ(coord2.y(), 0);
        ASSERT_EQ(coord2.resWidth(), 0);
        ASSERT_EQ(coord2.resHeight(), 0);
        GU::CameraCoordinate coord5;
        coord5 = std::move(coord4);
        ASSERT_NE(coord5, coord2);
        ASSERT_EQ(coord5, coord3);
        ASSERT_EQ(coord4.x(), 0);
        ASSERT_EQ(coord4.y(), 0);
        ASSERT_EQ(coord4.resWidth(), 0);
        ASSERT_EQ(coord4.resHeight(), 0);
#endif
        const gu_camera_coordinate coord6 = {1, 2, 3, 4};
        GU::CameraCoordinate coord7 = coord6;
        GU::CameraCoordinate coord8;
        coord8 = coord6;
        ASSERT_EQ(coord7, coord6);
        ASSERT_EQ(coord8, coord6);
        ASSERT_EQ(coord7, coord8);
    }

    TEST_F(CameraCoordinateCPPTests, GettersSetters) {
        GU::CameraCoordinate coord = GU::CameraCoordinate(1, 2, 3, 4);
        ASSERT_EQ(coord.x(), 1);
        coord.set_x(5);
        ASSERT_EQ(coord.x(), 5);
        ASSERT_EQ(coord.y(), 2);
        coord.set_y(6);
        ASSERT_EQ(coord.y(), 6);
        ASSERT_EQ(coord.resWidth(), 3);
        coord.set_resWidth(7);
        ASSERT_EQ(coord.resWidth(), 7);
        ASSERT_EQ(coord.resHeight(), 4);
        coord.set_resHeight(8);
        ASSERT_EQ(coord.resHeight(), 8);
    }

    TEST_F(CameraCoordinateCPPTests, Equality) {
        const GU::CameraCoordinate topLeftEdge = GU::CameraCoordinate(0, 0, 1920, 1080);
        const GU::CameraCoordinate topRightEdge = GU::CameraCoordinate(1919, 0, 1920, 1080);
        const GU::CameraCoordinate bottomLeftEdge = GU::CameraCoordinate(0, 1079, 1920, 1080);
        const GU::CameraCoordinate bottomRightEdge = GU::CameraCoordinate(1919, 1079, 1920, 1080);
        const GU::CameraCoordinate middle = GU::CameraCoordinate(960, 540, 1920, 1080);
        ASSERT_TRUE(topLeftEdge == topLeftEdge);
        ASSERT_TRUE(topRightEdge == topRightEdge);
        ASSERT_TRUE(bottomLeftEdge == bottomLeftEdge);
        ASSERT_TRUE(bottomRightEdge == bottomRightEdge);
        ASSERT_TRUE(middle == middle);
        ASSERT_FALSE(topLeftEdge == topRightEdge);
        ASSERT_FALSE(topRightEdge == bottomLeftEdge);
        ASSERT_FALSE(bottomLeftEdge == bottomRightEdge);
        ASSERT_FALSE(bottomRightEdge == middle);
    }

    TEST_F(CameraCoordinateCPPTests, PixelCoordinate) {
        cam_coord_to_px_coord_fake.return_val = { -959, 540, 1920, 1080 };
        const GU::CameraCoordinate topLeftEdge = GU::CameraCoordinate(0, 0, 1920, 1080);
        const GU::PixelCoordinate ptopLeftEdge = GU::PixelCoordinate(-959, 540, 1920, 1080);
        const GU::PixelCoordinate out = topLeftEdge.pixelCoordinate();
        ASSERT_EQ(cam_coord_to_px_coord_fake.call_count, 1);
        ASSERT_EQ(out, ptopLeftEdge);
    }

    TEST_F(CameraCoordinateCPPTests, PercentCoordinate) {
        cam_coord_to_px_coord_fake.return_val = { -959, 540, 1920, 1080 };
        px_coord_to_pct_coord_fake.return_val = { -1.0f, 1.0f };
        const GU::CameraCoordinate topLeftEdge = GU::CameraCoordinate(0, 0, 1920, 1080);
        const GU::PercentCoordinate ptopLeftEdge = GU::PercentCoordinate(-1.0f, 1.0f);
        const GU::PercentCoordinate out = topLeftEdge.percentCoordinate();
        ASSERT_EQ(cam_coord_to_px_coord_fake.call_count, 1);
        ASSERT_EQ(px_coord_to_pct_coord_fake.call_count, 1);
        ASSERT_EQ(out, ptopLeftEdge);
    }

}  // namespace

#pragma clang diagnostic pop