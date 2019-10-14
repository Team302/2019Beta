/*
 * LidarLite.h
 */

#ifndef SRC_MAIN_CPP_XMLHW_LIDARLITE_H_
#define SRC_MAIN_CPP_LIDARLITE_H_
#endif

// Third Party Includes
#include <pugixml/pugixml.hpp>

class LidarLiteDefn
{
        public:

            LidarLiteDefn() = default;
            virtual ~LidarLiteDefn() = default;


            //-----------------------------------------------------------------------
        // Method:      ParseXML
        // Description: Parse a lidar lite XML element and create a DragonLidarLite from
        //              its definition..
        // Returns:     void
        //-----------------------------------------------------------------------
        //DragonLidarLite* ParseXML
        void ParseXML
        (
            pugi::xml_node  lidarLiteNode
        );
};