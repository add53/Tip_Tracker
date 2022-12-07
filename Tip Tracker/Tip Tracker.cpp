// Tip Tracker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Header.h"


//Tip list
std::vector<Tip*> tip_list;

//Functions
    int week_number(const std::tm& tm) {

        constexpr int DAYS_PER_WEEK = 7;

        const int wday = tm.tm_wday;
        const int delta = wday ? wday - 1 : DAYS_PER_WEEK - 1;
        return (tm.tm_yday + DAYS_PER_WEEK - delta) / DAYS_PER_WEEK;
    }

    //meanVector Functions
    int listAmount;
    int meanVector(std::vector<int> list) {
        listAmount = 0;
        int listSize = list.size();
        if (listSize == 0) {
            return 0;
        }
        else {
            for (int i = 0; i < listSize; i++) {
                listAmount += list[i];
            }
            return listAmount / listSize;
        }
    }

    double listAmountDouble;
    double meanVector(std::vector<double> list) {
        listAmountDouble = 0;
        int listSize = list.size();
        if (listSize == 0) {
            return 0;
        }
        else {
            for (int i = 0; i < listSize; i++) {
                listAmountDouble += list[i];
            }
            return listAmountDouble / listSize;
        }
    }
    
    //Tip per Hour Function
    double tip_check;
    double hour_check;
    int TipPerHour(std::vector<int> list) {
        for (int i = 0; i < list.size(); i++) {
   
            tip_check += list[i];
            hour_check += tip_list[i]->getHours();
            return (tip_check / hour_check);
        }
    }

    //Go To Line Function
    std::string GotoLine(std::fstream& file, unsigned int num) {
        std::string file_return;
        file.seekg(std::ios::beg);
        for (int i = 0; i < num - 1; ++i) {
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        getline(file, file_return);
        return file_return;
    }

    //Read line string
    std::string fileStringRead;
    std::string GotoLineReadString(std::fstream& file, unsigned int num) {
        fileStringRead = GotoLine(file, num);
        return fileStringRead;
    }

    //Read line int
    int fileStringReadInt;
    int GotoLineReadInt(std::fstream& file, unsigned int num) {
        std::string fileStringRead;
        fileStringReadInt = stoi(GotoLine(file, num));
        return fileStringReadInt;
    }

    //Read line double
    double fileStringReadDouble;
    double GotoLineReadDouble(std::fstream& file, unsigned int num) {
        std::string fileStringRead;
        fileStringReadDouble = std::stod(GotoLine(file, num));
        return fileStringReadDouble;
    }

int tip_lines;
int tip_total;

int main() {
    //Variables
        //Numerical Variables 
        std::vector<double> tip_per_hour;

        //Input Variables
        std::string day_part_input;
        int tip_input;
        std::string day_input;
        double hours_worked;

        //Define File Variables
        std::fstream myFile;
        std::fstream tip_file("tip_amount.txt");
        std::fstream day_file("day.txt");
        std::fstream day_part_file("day_part.txt");
        std::fstream hours_file("Hours.txt");

        //Vectors for specific tip lists
        std::vector<int> Monday_tip = {};
        std::vector<int> Tuesday_tip = {};
        std::vector<int> Wednesday_tip = {};
        std::vector<int> Thursday_tip = {};
        std::vector<int> Friday_tip = {};
        std::vector<int> Saturday_tip = {};
        std::vector<int> Sunday_tip = {};

        std::vector<int> Night_tip = {};
        std::vector<int> Day_tip = {};
        std::vector<int> Double_tip = {};

        std::vector<int> MondayDay_tip = {};
        std::vector<int> TuesdayDay_tip = {};
        std::vector<int> WednesdayDay_tip = {};
        std::vector<int> ThursdayDay_tip = {};
        std::vector<int> FridayDay_tip = {};
        std::vector<int> SaturdayDay_tip = {};
        std::vector<int> SundayDay_tip = {};

        std::vector<int> MondayNight_tip = {};
        std::vector<int> TuesdayNight_tip = {};
        std::vector<int> WednesdayNight_tip = {};
        std::vector<int> ThursdayNight_tip = {};
        std::vector<int> FridayNight_tip = {};
        std::vector<int> SaturdayNight_tip = {};
        std::vector<int> SundayNight_tip = {};

        std::vector<int> MondayDouble_tip = {};
        std::vector<int> TuesdayDouble_tip = {};
        std::vector<int> WednesdayDouble_tip = {};
        std::vector<int> ThursdayDouble_tip = {};
        std::vector<int> FridayDouble_tip = {};
        std::vector<int> SaturdayDouble_tip = {};
        std::vector<int> SundayDouble_tip = {};

        //Tip Averages
        int tip_average_total;
        int tip_average_monday;
        int tip_average_tuesday;
        int tip_average_wednesday;
        int tip_average_thursday;
        int tip_average_friday;
        int tip_average_saturday;
        int tip_average_sunday;
        int tip_average_per_hour;

        int tip_average_MondayNight;
        int tip_average_TuesdayNight;
        int tip_average_WednesdayNight;
        int tip_average_ThursdayNight;
        int tip_average_FridayNight;
        int tip_average_SaturdayNight;
        int tip_average_SundayNight;

        int tip_average_MondayDay;
        int tip_average_TuesdayDay;
        int tip_average_WednesdayDay;
        int tip_average_ThursdayDay;
        int tip_average_FridayDay;
        int tip_average_SaturdayDay;
        int tip_average_SundayDay;

        int tip_average_MondayDouble;
        int tip_average_TuesdayDouble;
        int tip_average_WednesdayDouble;
        int tip_average_ThursdayDouble;
        int tip_average_FridayDouble;
        int tip_average_SaturdayDouble;
        int tip_average_SundayDouble;



        int tip_average_Night;
        int tip_average_Day;
        int tip_average_Double;

    //Check if the alt key is pressed, if it is, skip input
    std::cout << "Press X To Skip Input" << std::endl;
    char inputCheck = getchar();
    int value = inputCheck;
    while (value != KEY_X) {
        system("CLS");
        
        //User input for day
        std::cout << "Enter day: ";
        std::cin >> day_input;
        std::cout << "\n";
        myFile.open("day.txt", std::ios::app);
        if (myFile.is_open()) {
            myFile << day_input << std::endl;
            myFile.close();
        }
        else {
            std::cout << "Could not open file";
        }

        //User input for tip
        std::cout << "Enter tip amount: ";
        std::cin >> tip_input;
        std::cout << "\n";
        myFile.open("tip_amount.txt", std::ios::app);
        if (myFile.is_open()) {
            myFile << tip_input << std::endl;
            myFile.close();
        }
        else {
            std::cout << "Could not open file";
        }

        //User input for day part
        std::cout << "Enter day part: ";
        std::cin >> day_part_input;
        std::cout << std::endl;
        myFile.open("day_part.txt", std::ios::app);
        if (myFile.is_open()) {
            myFile << day_part_input << std::endl;
            myFile.close();
        }
        else {
            std::cout << "Could not open file";
        }

        //User input for hours
        std::cout << "Enter hours worked: ";
        std::cin >> hours_worked;
        std::cout << "\n";
        myFile.open("Hours.txt", std::ios::app);
        if (myFile.is_open()) {
            myFile << hours_worked << std::endl;
            myFile.close();
        }
        else {
            std::cout << "Could not open file";
        }
        break;
    }

    //Read file for tip totalh
    std::string tip_total_string;
    myFile.open("tip_amount.txt", std::ios::in);
    if (myFile.is_open()) {
        while (getline(myFile, tip_total_string)) {
            tip_total += stoi(tip_total_string);
            tip_lines++;
        }
        myFile.close();
    }

    //Create a new object in tip
    for (int i = 0; i < tip_lines; i++) {
        int tipListSize = tip_list.size();
        tip_list.push_back(new Tip(GotoLineReadString(day_part_file, (tipListSize + 1)), GotoLineReadInt(tip_file, (tipListSize + 1)), GotoLineReadString(day_file, (tipListSize + 1)), GotoLineReadDouble(hours_file, (tipListSize + 1))));
    }

    //Search through and find "Day"
    for (int i = 0; i < tip_list.size(); i++) {
        std::string day_check = tip_list[i]->getDay();
        std::string day_part_check = tip_list[i]->getDay_part();
        if (day_check == "Monday") {
            Monday_tip.push_back(tip_list[i]->getTip_Amount());
            if (day_part_check == "Night") {
                MondayNight_tip.push_back(tip_list[i]->getTip_Amount());
                Night_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Day") {
                MondayDay_tip.push_back(tip_list[i]->getTip_Amount());
                Day_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Double") {
                MondayDouble_tip.push_back(tip_list[i]->getTip_Amount());
                Double_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else {
                std::cout << "Error";
                return 0;
            }
        }
        else if (day_check == "Tuesday") {
            Tuesday_tip.push_back(tip_list[i]->getTip_Amount());
            if (day_part_check == "Night") {
                TuesdayNight_tip.push_back(tip_list[i]->getTip_Amount());
                Night_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Day") {
                TuesdayDay_tip.push_back(tip_list[i]->getTip_Amount());
                Day_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Double") {
                TuesdayDouble_tip.push_back(tip_list[i]->getTip_Amount());
                Double_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else {
                std::cout << "Error";
                return 0;
            }
        }
        else if (day_check == "Wednesday") {
            Wednesday_tip.push_back(tip_list[i]->getTip_Amount());
            if (day_part_check == "Night") {
                WednesdayNight_tip.push_back(tip_list[i]->getTip_Amount());
                Night_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Day") {
                WednesdayDay_tip.push_back(tip_list[i]->getTip_Amount());
                Day_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Double") {
                WednesdayDouble_tip.push_back(tip_list[i]->getTip_Amount());
                Double_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else {
                std::cout << "Error";
                return 0;
            }
        }
        else if (day_check == "Thursday") {
            Thursday_tip.push_back(tip_list[i]->getTip_Amount());
            if (day_part_check == "Night") {
                ThursdayNight_tip.push_back(tip_list[i]->getTip_Amount());
                Night_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Day") {
                ThursdayDay_tip.push_back(tip_list[i]->getTip_Amount());
                Day_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Double") {
                ThursdayDouble_tip.push_back(tip_list[i]->getTip_Amount());
                Double_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else {
                std::cout << "Error";
                return 0;
            }
        }
        else if (day_check == "Friday") {
            Friday_tip.push_back(tip_list[i]->getTip_Amount());
            if (day_part_check == "Night") {
                FridayNight_tip.push_back(tip_list[i]->getTip_Amount());
                Night_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Day") {
                FridayDay_tip.push_back(tip_list[i]->getTip_Amount());
                Day_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Double") {
                FridayDouble_tip.push_back(tip_list[i]->getTip_Amount());
                Double_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else {
                std::cout << "Error";
                return 0;
            }
        }
        else if (day_check == "Saturday") {
            Saturday_tip.push_back(tip_list[i]->getTip_Amount());
            if (day_part_check == "Night") {
                SaturdayNight_tip.push_back(tip_list[i]->getTip_Amount());
                Night_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Day") {
                SaturdayDay_tip.push_back(tip_list[i]->getTip_Amount());
                Day_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Double") {
                SaturdayDouble_tip.push_back(tip_list[i]->getTip_Amount());
                Double_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else {
                std::cout << "Error";
                return 0;
            }
        }
        else if (day_check == "Sunday") {
            Sunday_tip.push_back(tip_list[i]->getTip_Amount());
            if (day_part_check == "Night") {
                SundayNight_tip.push_back(tip_list[i]->getTip_Amount());
                Night_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Day") {
                SundayDay_tip.push_back(tip_list[i]->getTip_Amount());
                Day_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else if (day_part_check == "Double") {
                SundayDouble_tip.push_back(tip_list[i]->getTip_Amount());
                Double_tip.push_back(tip_list[i]->getTip_Amount());
            }
            else {
                std::cout << "Error";
                return 0;
            }
        }
        else {
            std::cout << "Error" << std::endl;
        }
    }

    //Find the average tip/hour
    for (int i = 0; i < tip_list.size(); i++) {
        double tip_check_total;
        double hour_check_total;
        tip_check_total = tip_list[i]->getTip_Amount();
        hour_check_total = tip_list[i]->getHours();
        tip_per_hour.push_back(tip_check_total / hour_check_total);
    }

    //Calculate averages
    tip_average_total = tip_total / tip_lines;

    tip_average_monday = meanVector(Monday_tip);
    tip_average_tuesday = meanVector(Tuesday_tip);
    tip_average_wednesday = meanVector(Wednesday_tip);
    tip_average_thursday = meanVector(Thursday_tip);
    tip_average_friday = meanVector(Friday_tip);
    tip_average_saturday = meanVector(Saturday_tip);
    tip_average_sunday = meanVector(Sunday_tip);

    tip_average_MondayNight = meanVector(MondayNight_tip);
    tip_average_TuesdayNight = meanVector(TuesdayNight_tip);
    tip_average_WednesdayNight = meanVector(WednesdayNight_tip);
    tip_average_ThursdayNight = meanVector(ThursdayNight_tip);
    tip_average_FridayNight = meanVector(FridayNight_tip);
    tip_average_SaturdayNight = meanVector(SaturdayNight_tip);
    tip_average_SundayNight = meanVector(SundayNight_tip);

    tip_average_MondayDay = meanVector(MondayDay_tip);
    tip_average_TuesdayDay = meanVector(TuesdayDay_tip);
    tip_average_WednesdayDay = meanVector(WednesdayDay_tip);
    tip_average_ThursdayDay = meanVector(ThursdayDay_tip);
    tip_average_FridayDay = meanVector(FridayDay_tip);
    tip_average_SaturdayDay = meanVector(SaturdayDay_tip);
    tip_average_SundayDay = meanVector(SundayDay_tip);

    tip_average_MondayDouble = meanVector(MondayDouble_tip);
    tip_average_TuesdayDouble = meanVector(TuesdayDouble_tip);
    tip_average_WednesdayDouble = meanVector(WednesdayDouble_tip);
    tip_average_ThursdayDouble = meanVector(ThursdayDouble_tip);
    tip_average_FridayDouble = meanVector(FridayDouble_tip);
    tip_average_SaturdayDouble = meanVector(SaturdayDouble_tip);
    tip_average_SundayDouble = meanVector(SundayDouble_tip);

    tip_average_Day = meanVector(Day_tip);
    tip_average_Night = meanVector(Night_tip);
    tip_average_Double = meanVector(Double_tip);

    tip_average_per_hour = meanVector(tip_per_hour);

    //Display stats
    system("CLS");
    std::cout << "Displaying Stats..." << std::endl << std::endl;
    std::cout << "Tip Average: " << tip_average_total << std::endl;
    std::cout << "Average Tip per Hour: " << tip_average_per_hour << std::endl;

    std::cout << std::endl;

    std::cout << "Monday Average: " << tip_average_monday << std::endl;
    std::cout << "Tuesday Average: " << tip_average_tuesday << std::endl;
    std::cout << "Wednesday Average: " << tip_average_wednesday << std::endl;
    std::cout << "Thursday Average: " << tip_average_thursday << std::endl;
    std::cout << "Friday Average: " << tip_average_friday << std::endl;
    std::cout << "Saturday Average: " << tip_average_saturday << std::endl;
    std::cout << "Sunday Average: " << tip_average_sunday << std::endl;

    std::cout << std::endl;

    std::cout << "Night Average: " << tip_average_Night << std::endl;
    std::cout << "Day Average: " << tip_average_Day << std::endl;
    std::cout << "Double Average: " << tip_average_Double << std::endl;

    std::cout << std::endl;

    std::cout << "Monday Night Average: " << tip_average_MondayNight << std::endl;
    std::cout << "Tuesday Night Average: " << tip_average_TuesdayNight << std::endl;
    std::cout << "Wednesday Night Average: " << tip_average_WednesdayNight << std::endl;
    std::cout << "Thursday Night Average: " << tip_average_ThursdayNight << std::endl;
    std::cout << "Friday Night Average: " << tip_average_FridayNight << std::endl;
    std::cout << "Saturday Night Average: " << tip_average_SaturdayNight << std::endl;
    std::cout << "Sunday Night Average: " << tip_average_SundayNight << std::endl;

    std::cout << std::endl;

    std::cout << "Monday Day Average: " << tip_average_MondayDay << std::endl;
    std::cout << "Tuesday Day Average: " << tip_average_TuesdayDay << std::endl;
    std::cout << "Wednesday Day Average: " << tip_average_WednesdayDay << std::endl;
    std::cout << "Thursday Day Average: " << tip_average_ThursdayDay << std::endl;
    std::cout << "Friday Day Average: " << tip_average_FridayDay << std::endl;
    std::cout << "Saturday Day Average: " << tip_average_SaturdayDay << std::endl;
    std::cout << "Sunday Day Average: " << tip_average_SundayDay << std::endl;

    std::cout << std::endl;

    std::cout << "Monday Double Average: " << tip_average_MondayDouble << std::endl;
    std::cout << "Tuesday Double Average: " << tip_average_TuesdayDouble << std::endl;
    std::cout << "Wednesday Double Average: " << tip_average_WednesdayDouble << std::endl;
    std::cout << "Thursday Double Average: " << tip_average_ThursdayDouble << std::endl;
    std::cout << "Friday Double Average: " << tip_average_FridayDouble << std::endl;
    std::cout << "Saturday Double Average: " << tip_average_SaturdayDouble << std::endl;
    std::cout << "Sunday Double Average: " << tip_average_SundayDouble << std::endl;

    std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
