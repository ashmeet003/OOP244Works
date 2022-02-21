/*
Name: Ashmeet Kaur
Seneca email: ashmeet-kaur1@myseneca.ca
Student Id: 122421217
Date: February 14, 2022
I have done all the coding by myself and only copied the code that my professor provided to
 complete my workshops and assignments.
*/
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
namespace sdds
{
    class Robot
    {
        char* m_name{};
        char* m_location{};
        double m_weight{};
        double m_width{};
        double m_height{};
        double m_speed{};
        bool m_deployed{};

    public:
        Robot();
        Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
        ~Robot();
        Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployed);
        void setLocation(const char* location);
        void setDeployed(bool deployed);
        const char* getName() const;
        const char* getLocation() const;
        bool isDeployed() const;
        bool isValid() const;
        double getSpeed() const;
        void display() const;
    };
    int conrtolRooomReport(const Robot robot[], int num_robots);
}
#endif