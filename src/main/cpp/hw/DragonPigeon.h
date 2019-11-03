/*
 * DragonPigeon.h
 *
 *  Created on: Feb 3, 2018
 *      Author: team302
 */

#pragma once

#include <memory>
#include <string>
#include <vector>

#include <ctre/phoenix/Sensors/PigeonIMU.h>


class DragonPigeon
{
    public:


        static DragonPigeon* GetPigeon();
        static DragonPigeon* CreatePigeon(int id);
        double GetPitch();
        double GetRoll();
        double GetYaw();

    private:
        DragonPigeon
        (
            int  canID
        );
        DragonPigeon() = delete;
        virtual ~DragonPigeon() = default;

        static DragonPigeon*        m_instance;
        std::unique_ptr<ctre::phoenix::sensors::PigeonIMU> m_pigeon;

        double m_initialRoll;
        double m_initialPitch;
        double m_initialYaw;

        // these methods correct orientation, but do not apply the initial offsets
        double GetRawRoll();
        double GetRawPitch();
        double GetRawYaw();
};



