
///====================================================================================================================================================
/// Copyright 2019 Lake Orion Robobitcs FIRST Team 302
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
/// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
/// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
/// OR OTHER DEALINGS IN THE SOFTWARE.
///====================================================================================================================================================

#pragma once

///========================================================================================================
/// IMechanism.h
///========================================================================================================
///
/// File Description:
///     This is the interface for all subsystems
///
///========================================================================================================

// C++ Includes
#include <vector>

// FRC includes

// Team 302 includes
#include <xmlhw/PIDData.h>
// Third Party Includes


///========================================================================================================
///	 Class:			IMechanism
///  Description:	Interface for subsystems
///========================================================================================================
class IMechanism
{
	public:

        ///==================================================================================
        /// enum:           MECHANISM_TYPE
        /// description:    Indicates the type of mechanism
        ///==================================================================================
        enum MECHANISM_TYPE
        {
            UNKNOWN_MECHANISM = -1,
            CHASSIS,
            WRIST,
            INTAKE,
            ARM,
            EXTENDER,
            CLIMBER,
            BEAK,
            TAIL,
            MAX_MECHANISM_TYPES
        };

        // todo:  move this
        enum MECHANISM_PARAM_TYPE
        {
            MECHANISM_PARAM_UNKNOWN = -1,
            LEGAL_STARTING_ANGLE,
            TEST_STARTING_ANGLE,
            EXTENDER_LEGAL_STARTING_INCHES,
            EXTENDER_TEST_STARTING_INCHES,
            HATCH_FLOOR_ANGLE,
            HATCH_HP_SECOND_ANGLE,
            HATCH_LOW_ANGLE,
            HATCH_MID_ANGLE,
            HATCH_HIGH_ANGLE,
            HATCH_LOW_SECOND_ANGLE,
            HATCH_MID_SECOND_ANGLE,
            HATCH_HIGH_SECOND_ANGLE,
            CARGO_FLOOR_ANGLE,
            CARGO_HP_ANGLE,
            CARGO_SHIP_ANGLE,
            CARGO_LOW_ANGLE,
            CARGO_MID_ANGLE,
            CARGO_HIGH_ANGLE,
            HATCH_FLOOR_EXTENSION,
            HATCH_HP_SECOND_EXTENSION,
            HATCH_LOW_EXTENSION,
            HATCH_MID_EXTENSION,
            HATCH_HIGH_EXTENSION,
            HATCH_LOW_SECOND_EXTENSION,
            HATCH_MID_SECOND_EXTENSION,
            HATCH_HIGH_SECOND_EXTENSION,
            CARGO_FLOOR_EXTENSION,
            CARGO_HP_EXTENSION,
            CARGO_HP_HOLE_EXTENSION,
            CARGO_SHIP_EXTENSION,
            CARGO_LOW_EXTENSION,
            CARGO_MID_EXTENSION,
            CARGO_HIGH_EXTENSION,
            CARGO_INTAKE_SPEED_PARAM,
            CARGO_OUTTAKE_SPEED_PARAM,
            HATCH_INTAKE_SPEED_PARAM,
            HATCH_OUTTAKE_SPEED_PARAM,
            SERVO_LOCKED_POSITION_PARAM,
            SERVO_DROPPED_POSITION_PARAM,
            HATCH_MECH_OPEN_ROTATIONS,
            MAX_MECHANISM_PARAM_TYPES
        };

        ///==================================================================================
        /// method:         GetType
        /// description:    Indicates the type of mechanism this is
        /// returns:        MECHANISM_TYPE
        ///==================================================================================
        virtual MECHANISM_TYPE GetType() const = 0;


        ///==================================================================================
        /// method:         SetPercentOutput
        /// description:    Run mechanism in open loop (percent output)
        /// returns:        void
        ///==================================================================================
        virtual void SetPercentOutput
        (
            double      value       /// <I> - percent output for the motor(s)
        ) = 0;


        ///==================================================================================
        /// method:         SetPosition
        /// description:    Run mechanism in closed loop position mode.  The value is in 
        ///                 inches or degrees.
        /// returns:        void
        ///==================================================================================
        virtual void SetPosition 
        (
            double      pos       /// <I> - target position in inches (translating mechanisms)  
				  ///       or degrees (rotating mechanisms) 
        ) = 0;


        ///==================================================================================
        /// method:         GetCurrentPostion
        /// description:    Return the current position of the mechanism.  The value is in 
        ///                 inches or degrees.
        /// returns:        double	position in inches (translating mechanisms) or degrees 
	///				(rotating mechanisms)
        ///==================================================================================
        virtual double GetCurrentPosition() const = 0;

        ///==================================================================================
        /// method:         GetTargetPostion
        /// description:    Return the targget position of the mechanism.  The value is in 
        ///                 inches or degrees.
        /// returns:        double	position in inches (translating mechanisms) or degrees
	///				(rotating mechanisms)
        ///==================================================================================
        virtual double GetTargetPosition() const = 0;

        ///==================================================================================
        /// method:         SetSpeed
        /// description:    Run mechanism in closed loop velocity mode.  The value is in 
        ///                 inches/second (translating mechanisms) or degrees/second (rotating 
	///		    mechanisms)
        /// returns:        void
        ///==================================================================================
        virtual void SetSpeed 
        (
            double      speed       /// <I> - target speed inches/second (translating mechanisms) or 
				    ///	      degrees/second (rotating mechanisms)
        ) = 0;

        ///==================================================================================
        /// method:         GetCuyrrentSpeed
        /// description:    Get the current speed of the mechanism.  The value is in 
        ///                 inches per second or degrees per second.
        /// returns:        double	speed in inches/second (translating mechanisms) or 
	///				degrees/second (rotating mechanisms)
        ///==================================================================================
        virtual double GetCurrentSpeed() const = 0;

        ///==================================================================================
        /// method:         GetTargetSpeecd
        /// description:    Get the target speed of the mechanism.  The value is in 
        ///                 inches per second or degrees per second.
        /// returns:        double	speed in inches/second (translating mechanisms) or 
	///				degrees/second (rotating mechanisms)
        ///==================================================================================
        virtual double GetTargetSpeed() const = 0; 
        
        // todo:  move functionality
	/*
        virtual void SetParam
        (
            IMechanism::MECHANISM_PARAM_TYPE    param,          // <I> - parameter to set
            double                              value           // <I> - parameter value
        ) = 0;

        // todo: move
        virtual void SetPID
        (
            PIDData*        pid                 // <I> - PID control information
        ) = 0;
	*/


	IMechanism() = default;
	virtual ~IMechanism() = default;
};
typedef std::vector<IMechanism*> IMechanismVector;



