#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <algorithm>  // Added for find()
#include <cstdio>     // Added for sscanf()
#include <iomanip>
#include <string>     // Added for explicit string inclusion
#include <sstream>    // Added for string conversion
#include <stdexcept>  // Added for exception handling

using namespace std;

// ====== Constants ======
const string BOX_HORIZONTAL = "═";
const string BOX_VERTICAL = "║";
const string BOX_TOP_LEFT = "╔";
const string BOX_TOP_RIGHT = "╗";
const string BOX_BOTTOM_LEFT = "╚";
const string BOX_BOTTOM_RIGHT = "╝";

// ====== Manual Implementation of Sleep Function ======
void manualSleep(int seconds) {
    // Simple busy-wait implementation
    time_t start = time(0);
    while (time(0) - start < seconds) {
        // Busy wait
    }
}

// ====== Utility Functions ======
string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d", ltm);
    return string(buffer);
}

// Get current time for workout tracking
string getCurrentTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%H:%M:%S", ltm);
    return string(buffer);
}

// Replace spaces with underscores in a string
string replaceSpacesWithUnderscores(string str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        if (result[i] == ' ') {
            result[i] = '_';
        }
    }
    return result;
}

// Replace underscores with spaces in a string
string replaceUnderscoresWithSpaces(string str) {
    string result = str;
    for (size_t i = 0; i < result.length(); i++) {
        if (result[i] == '_') {
            result[i] = ' ';
        }
    }
    return result;
}

// Generate a random motivational quote
string getRandomMotivationalQuote() {
    string quotes[] = {
        "The only bad workout is the one that didn't happen.",
        "Your body can stand almost anything. It's your mind that you have to convince.",
        "The hard days are the best because that's when champions are made.",
        "Good things come to those who sweat.",
        "Fitness is not about being better than someone else. It's about being better than you used to be.",
        "The only place where success comes before work is in the dictionary.",
        "Don't stop when you're tired. Stop when you're done.",
        "You're only one workout away from a good mood.",
        "Exercise is a celebration of what your body can do, not a punishment for what you ate.",
        "The pain you feel today will be the strength you feel tomorrow."
    };
    
    int randomIndex = rand() % 10; // 10 quotes in the array
    return quotes[randomIndex];
}

// Simple password hashing function
string hashPassword(const string& password) {
    // Simple hashing algorithm for demonstration (not for production use)
    string hashed = "";
    for (char c : password) {
        hashed += to_string((int)(c) * 7 % 127);
    }
    return hashed;
}

// Convert double to string with fixed precision
string doubleToString(double value) {
    stringstream stream;
    stream << fixed << setprecision(2) << value;
    return stream.str();
}

// ====== Abstract Person Class ======
class Person {
protected:
    string username;
    double weight; // in kg
    double height; // in meters
    int age;

public:
    Person() : weight(0), height(0), age(0) {}
    Person(string _username, double _weight = 0, double _height = 0, int _age = 0)
        : username(_username), weight(_weight), height(_height), age(_age) {}
    
    // Virtual destructor for proper cleanup in derived classes
    virtual ~Person() {}

    // Pure virtual function to make this an abstract class
    virtual void displayInfo() const = 0;

    // Common utility functions
    double calculateBMI() const {
        if (weight <= 0 || height <= 0) return 0;
        return weight / (height * height);
    }

    string getBMICategory() const {
        double bmi = calculateBMI();
        if (bmi < 18.5) return "Underweight";
        else if (bmi < 25) return "Normal";
        else if (bmi < 30) return "Overweight";
        else return "Obese";
    }

    // Getters and setters
    string getUsername() const { return username; }
    void setUsername(string _username) { username = _username; }
    double getWeight() const { return weight; }
    void setWeight(double _weight) { weight = _weight; }
    double getHeight() const { return height; }
    void setHeight(double _height) { height = _height; }
    int getAge() const { return age; }
    void setAge(int _age) { age = _age; }
};

// ====== User Class (inherits from Person) ======
class User : public Person {
private:
    int points; // Private points

public:
    string password;
    int id;
    string background;
    int streak;
    int maxStreak;
    string badge;
    double totalCalories;
    double totalCO2;
    vector<string> unlockedExercises;
    vector<string> workoutHistory;
    vector<string> goals;
    string fitnessLevel; // Beginner, Intermediate, Advanced
    vector<pair<string, double>> personalBests; // Exercise name and personal best
    int consecutiveLoginDays;
    string lastLoginDate;

    User() : Person(), points(0), id(0), streak(0), maxStreak(0), badge("Beginner"), 
             totalCalories(0), totalCO2(0), fitnessLevel("Beginner"), consecutiveLoginDays(0) {}

    User(int _id, string _username, string _password, string _background)
        : Person(_username), id(_id), password(_password), background(_background),
          points(0), streak(0), maxStreak(0), badge("Beginner"), totalCalories(0), totalCO2(0),
          fitnessLevel("Beginner"), consecutiveLoginDays(1) {
        unlockedExercises = {"Push-ups", "Squats"}; // Default unlocked exercises
        lastLoginDate = getCurrentDate();
    }

    // Implement the pure virtual function from Person
    void displayInfo() const override {
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║                  👨 USER PROFILE                  ║\n";
        cout << "╠══════════════════════════════════════════════════╣\n";
        cout << "║ ID:              " << id << string(39 - to_string(id).length(), ' ') << "║\n";
        cout << "║ Name:            " << username << string(39 - username.length(), ' ') << "║\n";
        cout << "║ Background:      " << background << string(39 - background.length(), ' ') << "║\n";
        cout << "║ Fitness Level:   " << fitnessLevel << string(39 - fitnessLevel.length(), ' ') << "║\n";
        cout << "║ Current Streak:  " << streak << string(39 - to_string(streak).length(), ' ') << "║\n";
        cout << "║ Max Streak:      " << maxStreak << string(39 - to_string(maxStreak).length(), ' ') << "║\n";
        cout << "║ Badge:           " << badge << string(39 - badge.length(), ' ') << "║\n";
        cout << "║ Points:          " << points << string(39 - to_string(points).length(), ' ') << "║\n";
        cout << "║ Login Streak:    " << consecutiveLoginDays << string(39 - to_string(consecutiveLoginDays).length(), ' ') << "║\n";
        
        if (weight > 0 && height > 0) {
            double bmi = calculateBMI();
            string bmiStr = doubleToString(bmi);
            string bmiCategory = getBMICategory();
            
            cout << "║ Weight (kg):     " << weight << string(39 - doubleToString(weight).length(), ' ') << "║\n";
            cout << "║ Height (m):      " << height << string(39 - doubleToString(height).length(), ' ') << "║\n";
            cout << "║ BMI:             " << bmiStr << " (" << bmiCategory << ")" << string(39 - bmiStr.length() - 3 - bmiCategory.length(), ' ') << "║\n";
        }
        
        string calStr = doubleToString(totalCalories);
        string co2Str = doubleToString(totalCO2);
        cout << "║ Total Calories:  " << calStr << " kcal" << string(34 - calStr.length(), ' ') << "║\n";
        cout << "║ Total CO₂ Saved: " << co2Str << " g" << string(37 - co2Str.length(), ' ') << "║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        
        cout << "\n🔓 Unlocked Exercises: ";
        for (size_t i = 0; i < unlockedExercises.size(); i++) {
            cout << unlockedExercises[i];
            if (i < unlockedExercises.size() - 1) {
                cout << ", ";
            }
        }
        cout << "\n";
    }

    void updateBadge() {
        if (points >= 100) badge = "🌟 Legend";
        else if (points >= 75) badge = "🔥 Elite";
        else if (points >= 50) badge = "💪 Pro";
        else if (points >= 25) badge = "🏅 Intermediate";
        else badge = "🌱 Beginner";
    }

    void addPoints(int p) {
        points += p;
        updateBadge();
    }

    int getPoints() const {
        return points;
    }

    // Update user's fitness level based on points and workout history
    void updateFitnessLevel() {
        if (points >= 100 && workoutHistory.size() >= 20) {
            fitnessLevel = "Advanced";
        } else if (points >= 50 && workoutHistory.size() >= 10) {
            fitnessLevel = "Intermediate";
        } else {
            fitnessLevel = "Beginner";
        }
    }

    // Add a goal
    void addGoal(const string& goal) {
        goals.push_back(goal);
        cout << "\n🎯 New goal added: " << goal << "\n";
    }

    // Display goals
    void displayGoals() const {
        cout << "\n🎯 Your Fitness Goals:\n";
        if (goals.empty()) {
            cout << "No goals set yet. Add some goals to track your progress!\n";
        } else {
            for (size_t i = 0; i < goals.size(); i++) {
                cout << " " << (i + 1) << ". " << goals[i] << "\n";
            }
        }
    }

    // Update personal best
    void updatePersonalBest(const string& exercise, double value) {
        bool found = false;
        for (size_t i = 0; i < personalBests.size(); i++) {
            if (personalBests[i].first == exercise) {
                if (value > personalBests[i].second) {
                    personalBests[i].second = value;
                    cout << "\n🏆 New personal best for " << exercise << ": " << value << "!\n";
                }
                found = true;
                break;
            }
        }
        
        if (!found) {
            personalBests.push_back(make_pair(exercise, value));
            cout << "\n🏆 First personal best recorded for " << exercise << ": " << value << "!\n";
        }
    }

    // Display personal bests
    void displayPersonalBests() const {
        cout << "\n🏆 Your Personal Bests:\n";
        if (personalBests.empty()) {
            cout << "No personal bests recorded yet. Complete workouts to track your records!\n";
        } else {
            for (size_t i = 0; i < personalBests.size(); i++) {
                cout << " - " << personalBests[i].first << ": " << personalBests[i].second << "\n";
            }
        }
    }

    // Check and update login streak
    void checkLoginStreak() {
        string currentDate = getCurrentDate();
        
        // If this is not the first login
        if (!lastLoginDate.empty()) {
            time_t now = time(0);
            tm nowTm = *localtime(&now);
            
            tm lastTm;
            memset(&lastTm, 0, sizeof(lastTm));
            
            int year, month, day;
            if (sscanf(lastLoginDate.c_str(), "%d-%d-%d", &year, &month, &day) == 3) {
                lastTm.tm_year = year - 1900;
                lastTm.tm_mon = month - 1;
                lastTm.tm_mday = day;
                
                time_t lastTime = mktime(&lastTm);
                double diffSeconds = difftime(now, lastTime);
                int diffDays = static_cast<int>(diffSeconds / (60 * 60 * 24));
                
                if (diffDays == 1) {
                    // Consecutive login
                    consecutiveLoginDays++;
                    cout << "\n🔥 " << consecutiveLoginDays << " day login streak! Keep it up!\n";
                    
                    // Award bonus points for streaks at certain milestones
                    if (consecutiveLoginDays == 7) {
                        addPoints(10);
                        cout << "\n🎁 Bonus: +10 points for 7-day streak!\n";
                    } else if (consecutiveLoginDays == 30) {
                        addPoints(50);
                        cout << "\n🎁 Bonus: +50 points for 30-day streak!\n";
                    }
                } else if (diffDays > 1) {
                    // Streak broken
                    consecutiveLoginDays = 1;
                    cout << "\n🔄 Login streak reset. Starting fresh today!\n";
                }
                // If diffDays is 0, it's the same day login, no change to streak
            } else {
                // Invalid date format, reset streak
                consecutiveLoginDays = 1;
                cout << "\n⚠️ Could not parse previous login date. Streak reset.\n";
            }
        }
        
        lastLoginDate = currentDate;
    }

    // Enhanced profile display
    void displayProfile() const {
        displayInfo(); // Call the virtual method from the Person class
    }

    void unlockExercise(const string& exercise) {
        if (find(unlockedExercises.begin(), unlockedExercises.end(), exercise) == unlockedExercises.end()) {
            unlockedExercises.push_back(exercise);
            cout << "\n🎉 New Exercise Unlocked: " << exercise << "!\n";
        }
    }

    // Enhanced workout logging with more details
    void logWorkout(const string& exercise, int duration, int intensity, double caloriesBurned) {
        string entry = exercise + " (" + to_string(duration) + " min, intensity " + to_string(intensity) + 
        "/10) - " + doubleToString(caloriesBurned) + " kcal on " + getCurrentDate() + " at " + getCurrentTime();
        workoutHistory.push_back(entry);
        
        // Update fitness level after workout
        updateFitnessLevel();
    }

    void displayWorkoutHistory() const {
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════════════════════════════════╗\n";
        cout << "║                               📅 WORKOUT HISTORY                              ║\n";
        cout << "╚══════════════════════════════════════════════════════════════════════════════╝\n";
        
        if (workoutHistory.empty()) {
            cout << "No workouts recorded yet. Start exercising to track your progress!\n";
        } else {
            for (size_t i = 0; i < workoutHistory.size(); i++) {
                cout << " " << (i + 1) << ". " << workoutHistory[i] << "\n";
            }
        }
    }

    void displayLockedExercises() const {
        cout << "\n🔒 Locked Exercises:\n";
        if (points < 25) {
            cout << " - Running (Requires 25 points)\n";
        }
        if (points < 50) {
            cout << " - Cycling (Requires 50 points)\n";
        }
        if (points < 75) {
            cout << " - Jumping Jacks (Requires 75 points)\n";
        }
        if (points < 100) {
            cout << " - Plank (Requires 100 points)\n";
        }
        if (points < 125) {
            cout << " - Mountain Climbers (Requires 125 points)\n";
        }
    }
};

// ====== Abstract Authentication System Class ======
class AuthenticationSystem {
public:
    virtual ~AuthenticationSystem() {} // Virtual destructor
    virtual bool login(string username, string password, User &loggedInUser) = 0;
    virtual void registerUser(string username, string password, string background) = 0;
    virtual void deleteUser(string username) = 0;
    virtual bool resetPassword(const string& username, const string& newPassword) = 0;
    virtual bool validateUsername(const string& username) const = 0;
    virtual bool validatePassword(const string& password) const = 0;
};

// ====== Login System Class (inherits from AuthenticationSystem) ======
class LoginSystem : public AuthenticationSystem {
private:
    map<string, User> users;

public:
    LoginSystem() {
        // Seed random number generator for motivational quotes
        srand(static_cast<unsigned int>(time(0)));
        loadUsers();
    }

    void loadUsers() {
        ifstream file("users.txt");
        if (file.is_open()) {
            cout << "Loading users from file...\n"; // Debug statement
            
            string line;
            while (getline(file, line)) {
                // Skip empty lines
                if (line.empty()) continue;
                
                // Parse basic user data
                int id = 0, points = 0, streak = 0, maxStreak = 0, consecutiveLoginDays = 0;
                double totalCalories = 0.0, totalCO2 = 0.0, weight = 0.0, height = 0.0;
                int age = 0;
                string username, password, background, fitnessLevel, lastLoginDate;
                
                // Use stringstream for safer parsing
                stringstream ss(line);
                ss >> id >> username >> password >> background >> points >> streak >> maxStreak 
                   >> totalCalories >> totalCO2 >> weight >> height >> age >> fitnessLevel 
                   >> consecutiveLoginDays;
                
                // Get the rest of the line as the last login date
                getline(ss, lastLoginDate);
                // Remove leading whitespace
                if (!lastLoginDate.empty() && lastLoginDate[0] == ' ') {
                    lastLoginDate = lastLoginDate.substr(1);
                }
                
                // Replace underscores with spaces in the background and fitness level
                background = replaceUnderscoresWithSpaces(background);
                fitnessLevel = replaceUnderscoresWithSpaces(fitnessLevel);
                
                // Create user
                User user(id, username, password, background);
                user.addPoints(points); // Use addPoints to update badge
                user.streak = streak;
                user.maxStreak = maxStreak;
                user.totalCalories = totalCalories;
                user.totalCO2 = totalCO2;
                
                // Set new fields if they were loaded
                if (weight > 0) user.setWeight(weight);
                if (height > 0) user.setHeight(height);
                if (age > 0) user.setAge(age);
                if (!fitnessLevel.empty()) user.fitnessLevel = fitnessLevel;
                if (consecutiveLoginDays > 0) user.consecutiveLoginDays = consecutiveLoginDays;
                if (!lastLoginDate.empty()) user.lastLoginDate = lastLoginDate;
                
                // Load unlocked exercises based on points
                user.unlockedExercises = {"Push-ups", "Squats"};
                if (points >= 25) {
                    user.unlockExercise("Running");
                }
                if (points >= 50) {
                    user.unlockExercise("Cycling");
                }
                if (points >= 75) {
                    user.unlockExercise("Jumping Jacks");
                }
                if (points >= 100) {
                    user.unlockExercise("Plank");
                }
                if (points >= 125) {
                    user.unlockExercise("Mountain Climbers");
                }
                
                users[username] = user;
                cout << "Loaded user: " << username << " (Points: " << points << ")\n"; // Debug statement
            }
            file.close();
        } else {
            cout << "File not found or empty. Creating default users...\n"; // Debug statement
            // Default users if file doesn't exist
            users["Waqar"] = User(101, "Waqar", hashPassword("W123"), "Athlete");
            users["Anas"] = User(102, "Anas", hashPassword("A123"), "Weightlifter");
            users["Tuheed"] = User(103, "Tuheed", hashPassword("T123"), "Yoga Enthusiast");
            saveUsers(); // Save default users to file
        }
    }

    void saveUsers() {
        // Use a relative file path
        string filePath = "users.txt";
        ofstream file(filePath);

        if (file.is_open()) {
            cout << "Saving users to file...\n"; // Debug statement
            for (const auto& [username, user] : users) {
                file << user.id << " " << user.getUsername() << " " << user.password << " "
                     << replaceSpacesWithUnderscores(user.background) << " " << user.getPoints() << " " << user.streak << " "
                     << user.maxStreak << " " << user.totalCalories << " " << user.totalCO2 << " "
                     << user.getWeight() << " " << user.getHeight() << " " << user.getAge() << " "
                     << replaceSpacesWithUnderscores(user.fitnessLevel) << " " << user.consecutiveLoginDays << " "
                     << user.lastLoginDate << "\n";
                cout << "Saved user: " << user.getUsername() << "\n"; // Debug statement
            }
            file.close();
        } else {
            cout << "Error: Unable to save users to file!\n"; // Debug statement
        }
    }

    // Implementation of AuthenticationSystem methods
    bool login(string username, string password, User &loggedInUser) override {
        // For demonstration - in real application, we would hash the password
        auto it = users.find(username);
        if (it != users.end() && it->second.password == hashPassword(password)) {
            loggedInUser = it->second;
            // Update login streak
            loggedInUser.checkLoginStreak();
            // Save the updated streak information
            users[username] = loggedInUser;
            saveUsers();
            return true;
        }
        return false;
    }

    void registerUser(string username, string password, string background) override {
        // Validate input
        if (!validateUsername(username)) {
            cout << "\n❌ Invalid username! Username must be 3-20 characters long.\n";
            return;
        }
        
        if (!validatePassword(password)) {
            cout << "\n❌ Invalid password! Password must be at least 4 characters long.\n";
            return;
        }
        
        // Check if username already exists
        if (users.find(username) != users.end()) {
            cout << "\n❌ Username already exists! Please choose another one.\n";
            return;
        }
        
        int newId = users.size() + 101;
        // Hash password before storing
        User newUser(newId, username, hashPassword(password), background);
        users[username] = newUser;
        saveUsers();
        cout << "\n✅ Registration Successful! Please login.\n";
    }

    void deleteUser(string username) override {
        auto it = users.find(username);
        if (it != users.end()) {
            users.erase(it);
            saveUsers();
            cout << "\n✅ User " << username << " deleted successfully!\n";
        } else {
            cout << "\n❌ User not found!\n";
        }
    }

    bool resetPassword(const string& username, const string& newPassword) override {
        if (!validatePassword(newPassword)) {
            cout << "\n❌ Invalid password! Password must be at least 4 characters long.\n";
            return false;
        }
        
        auto it = users.find(username);
        if (it != users.end()) {
            it->second.password = hashPassword(newPassword);
            saveUsers();
            return true;
        }
        return false;
    }

    bool validateUsername(const string& username) const override {
        // Simple validation: username must be 3-20 characters
        return username.length() >= 3 && username.length() <= 20;
    }

    bool validatePassword(const string& password) const override {
        // Simple validation: password must be at least 4 characters
        return password.length() >= 4;
    }

    map<string, User>& getUsers() {
        return users;
    }
    
    void updateUser(const User& user) {
        users[user.getUsername()] = user;
        saveUsers();
    }
    
    bool changePassword(const string& username, const string& oldPassword, const string& newPassword) {
        if (!validatePassword(newPassword)) {
            cout << "\n❌ Invalid new password! Password must be at least 4 characters long.\n";
            return false;
        }
        
        auto it = users.find(username);
        if (it != users.end() && it->second.password == hashPassword(oldPassword)) {
            it->second.password = hashPassword(newPassword);
            saveUsers();
            return true;
        }
        return false;
    }
};

// ====== Leaderboard System ======
class Leaderboard {
public:
    void updateLeaderboard(map<string, User>& users) {
        if (users.empty()) {
            cout << "\n⚠️ No users found. Leaderboard is empty.\n";
            return;
        }
        
        vector<User> userRankings;
        for (const auto& [username, user] : users) {
            userRankings.push_back(user);
        }

        // Sort users by points (higher to lower)
        sort(userRankings.begin(), userRankings.end(), 
            [](const User& a, const User& b) { return a.getPoints() > b.getPoints(); });

        cout << "\n";
        cout << "╔═════════════════════════════════════════════════════╗\n";
        cout << "║                   🏆 LEADERBOARD 🏆                  ║\n";
        cout << "╠═════════════════════════════════════════════════════╣\n";
        cout << "║ Rank | User        | Points | Streak | Badge        ║\n";
        cout << "╠═════════════════════════════════════════════════════╣\n";
        
        for (size_t i = 0; i < userRankings.size(); i++) {
            string medal;
            if (i == 0) medal = "🥇";
            else if (i == 1) medal = "🥈";
            else if (i == 2) medal = "🥉";
            else medal = "  ";

            // Format the output with proper spacing
            string rank = medal + " " + to_string(i + 1);
            string user = userRankings[i].getUsername();
            string points = to_string(userRankings[i].getPoints());
            string streak = to_string(userRankings[i].streak);
            string badge = userRankings[i].badge;

            cout << "║ " << rank;
            for (int j = 0; j < 5 - static_cast<int>(rank.length()); j++) cout << " ";
            
            cout << "| " << user;
            for (int j = 0; j < 12 - static_cast<int>(user.length()); j++) cout << " ";
            
            cout << "| " << points;
            for (int j = 0; j < 7 - static_cast<int>(points.length()); j++) cout << " ";
            
            cout << "| " << streak;
            for (int j = 0; j < 7 - static_cast<int>(streak.length()); j++) cout << " ";
            
            cout << "| " << badge;
            for (int j = 0; j < 13 - static_cast<int>(badge.length()); j++) cout << " ";
            
            cout << "║\n";
        }
        
        cout << "╚═════════════════════════════════════════════════════╝\n";
    }
};

// ====== Exercise Class ======
class Exercise {
private:
    string name;
    string description;
    vector<string> steps;
    double caloriesPerMinute;
    double co2SavedPerMinute;
    int difficulty; // 1-10 scale
    string muscleGroup;
    string imageFilename;
    int pointsReward;
    
public:
    Exercise() : caloriesPerMinute(0), co2SavedPerMinute(0), difficulty(1), pointsReward(1) {}
    
    Exercise(string _name, string _description, double _caloriesPerMinute, double _co2SavedPerMinute, 
             int _difficulty, string _muscleGroup, int _pointsReward, string _imageFilename = "")
        : name(_name), description(_description), caloriesPerMinute(_caloriesPerMinute), 
          co2SavedPerMinute(_co2SavedPerMinute), difficulty(_difficulty), muscleGroup(_muscleGroup),
          pointsReward(_pointsReward), imageFilename(_imageFilename) {}
    
    // Add exercise steps
    void addStep(const string& step) {
        steps.push_back(step);
    }
    
    // Display exercise information
    void displayInfo() const {
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║                  🏋️ " << name << string(37 - name.length(), ' ') << "║\n";
        cout << "╠══════════════════════════════════════════════════╣\n";
        cout << "║ " << description << string(50 - description.length(), ' ') << "║\n";
        cout << "╠══════════════════════════════════════════════════╣\n";
        cout << "║ 🔥 Calories: " << caloriesPerMinute << " kcal/min" << string(33 - doubleToString(caloriesPerMinute).length(), ' ') << "║\n";
        cout << "║ 🌱 CO₂ Saved: " << co2SavedPerMinute << " g/min" << string(33 - doubleToString(co2SavedPerMinute).length(), ' ') << "║\n";
        cout << "║ 💪 Difficulty: " << difficulty << "/10" << string(37 - to_string(difficulty).length(), ' ') << "║\n";
        cout << "║ 🏋️ Muscle Group: " << muscleGroup << string(34 - muscleGroup.length(), ' ') << "║\n";
        cout << "║ 🎯 Points Reward: " << pointsReward << string(33 - to_string(pointsReward).length(), ' ') << "║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        
        // Display steps if available
        if (!steps.empty()) {
            cout << "\n📋 Steps to perform this exercise:\n";
            for (size_t i = 0; i < steps.size(); i++) {
                cout << " " << (i + 1) << ". " << steps[i] << "\n";
            }
        }
    }
    
    // Getters
    string getName() const { return name; }
    string getDescription() const { return description; }
    double getCaloriesPerMinute() const { return caloriesPerMinute; }
    double getCO2SavedPerMinute() const { return co2SavedPerMinute; }
    int getDifficulty() const { return difficulty; }
    string getMuscleGroup() const { return muscleGroup; }
    string getImageFilename() const { return imageFilename; }
    int getPointsReward() const { return pointsReward; }
    vector<string> getSteps() const { return steps; }
};

// ====== Exercise Manager Class ======
class ExerciseManager {
private:
    vector<Exercise> exercises;
    
public:
    ExerciseManager() {
        initializeExercises();
    }
    
    void initializeExercises() {
        // Create default exercises
        // 1. Push-ups
        Exercise pushups("Push-ups", "Upper body strength exercise", 8.0, 2.5, 5, "Chest, Triceps, Shoulders", 5);
        pushups.addStep("Start in a plank position with hands slightly wider than shoulder-width.");
        pushups.addStep("Lower your body until your chest nearly touches the floor.");
        pushups.addStep("Push yourself back up to the starting position.");
        pushups.addStep("Keep your core tight and back straight throughout the movement.");
        exercises.push_back(pushups);
        
        // 2. Squats
        Exercise squats("Squats", "Lower body strength exercise", 8.5, 2.8, 4, "Quadriceps, Glutes, Hamstrings", 5);
        squats.addStep("Stand with feet shoulder-width apart.");
        squats.addStep("Bend your knees and lower your body as if sitting in a chair.");
        squats.addStep("Keep your back straight and knees over your toes.");
        squats.addStep("Return to standing position.");
        exercises.push_back(squats);
        
        // 3. Running
        Exercise running("Running", "Cardiovascular endurance exercise", 12.0, 3.5, 6, "Full Body, Cardio", 8);
        running.addStep("Start with a light warm-up walk or jog.");
        running.addStep("Increase your pace to a comfortable running speed.");
        running.addStep("Keep your back straight and look ahead.");
        running.addStep("Land on the middle of your foot and roll through to the toe.");
        running.addStep("Breathe naturally and maintain a steady pace.");
        exercises.push_back(running);
        
        // 4. Cycling
        Exercise cycling("Cycling", "Lower body and cardiovascular exercise", 10.0, 5.0, 5, "Quadriceps, Hamstrings, Cardio", 7);
        cycling.addStep("Adjust the seat height so your leg is almost fully extended at the bottom of the pedal stroke.");
        cycling.addStep("Start pedaling at a comfortable pace.");
        cycling.addStep("Keep your back straight and core engaged.");
        cycling.addStep("Increase resistance for a harder workout or decrease for an easier one.");
        exercises.push_back(cycling);
        
        // 5. Jumping Jacks
        Exercise jumpingJacks("Jumping Jacks", "Full body cardio exercise", 8.0, 2.0, 3, "Full Body, Cardio", 4);
        jumpingJacks.addStep("Start standing with feet together and arms at your sides.");
        jumpingJacks.addStep("Jump and spread your feet beyond shoulder-width while raising arms overhead.");
        jumpingJacks.addStep("Jump again and return to the starting position.");
        jumpingJacks.addStep("Repeat at a quick pace.");
        exercises.push_back(jumpingJacks);
        
        // 6. Plank
        Exercise plank("Plank", "Core strength and stability exercise", 5.0, 1.5, 7, "Core, Shoulders", 6);
        plank.addStep("Start in a push-up position but with your weight on your forearms.");
        plank.addStep("Keep your body in a straight line from head to heels.");
        plank.addStep("Engage your core and hold the position.");
        plank.addStep("Breathe normally and maintain proper form.");
        exercises.push_back(plank);
        
        // 7. Mountain Climbers
        Exercise mountainClimbers("Mountain Climbers", "Full body cardio and core exercise", 9.0, 2.7, 8, "Core, Cardio", 10);
        mountainClimbers.addStep("Start in a plank position with arms straight.");
        mountainClimbers.addStep("Bring one knee toward your chest.");
        mountainClimbers.addStep("Quickly switch legs, bringing the other knee forward.");
        mountainClimbers.addStep("Continue alternating legs at a fast pace.");
        exercises.push_back(mountainClimbers);
    }
    
    // Get exercise by name
    Exercise* getExerciseByName(const string& name) {
        for (size_t i = 0; i < exercises.size(); i++) {
            if (exercises[i].getName() == name) {
                return &exercises[i];
            }
        }
        return nullptr;
    }
    
    // Display all exercises
    void displayAllExercises() const {
        cout << "\n";
        cout << "╔═════════════════════════════════════════════════════════════════╗\n";
        cout << "║                     🏋️ AVAILABLE EXERCISES                      ║\n";
        cout << "╚═════════════════════════════════════════════════════════════════╝\n";
        
        for (size_t i = 0; i < exercises.size(); i++) {
            cout << " " << (i + 1) << ". " << exercises[i].getName() << " - " 
                 << exercises[i].getDescription() << " (Difficulty: " 
                 << exercises[i].getDifficulty() << "/10)\n";
        }
    }
    
    // Display exercises by muscle group
    void displayExercisesByMuscleGroup(const string& muscleGroup) const {
        cout << "\n";
        cout << "╔═════════════════════════════════════════════════════════════════╗\n";
        cout << "║               🏋️ EXERCISES FOR " << muscleGroup << string(34 - muscleGroup.length(), ' ') << "║\n";
        cout << "╚═════════════════════════════════════════════════════════════════╝\n";
        
        bool found = false;
        for (size_t i = 0; i < exercises.size(); i++) {
            if (exercises[i].getMuscleGroup().find(muscleGroup) != string::npos) {
                cout << " " << (i + 1) << ". " << exercises[i].getName() << " - " 
                     << exercises[i].getDescription() << " (Difficulty: " 
                     << exercises[i].getDifficulty() << "/10)\n";
                found = true;
            }
        }
        
        if (!found) {
            cout << "No exercises found for this muscle group.\n";
        }
    }
    
    // Filter exercises by difficulty
    void displayExercisesByDifficulty(int minDifficulty, int maxDifficulty) const {
        cout << "\n";
        cout << "╔═════════════════════════════════════════════════════════════════╗\n";
        cout << "║           🏋️ EXERCISES WITH DIFFICULTY " << minDifficulty << "-" << maxDifficulty << string(24 - to_string(minDifficulty).length() - to_string(maxDifficulty).length(), ' ') << "║\n";
        cout << "╚═════════════════════════════════════════════════════════════════╝\n";
        
        bool found = false;
        for (size_t i = 0; i < exercises.size(); i++) {
            int difficulty = exercises[i].getDifficulty();
            if (difficulty >= minDifficulty && difficulty <= maxDifficulty) {
                cout << " " << (i + 1) << ". " << exercises[i].getName() << " - " 
                     << exercises[i].getDescription() << " (Difficulty: " 
                     << difficulty << "/10)\n";
                found = true;
            }
        }
        
        if (!found) {
            cout << "No exercises found in this difficulty range.\n";
        }
    }
    
    // Get exercises count
    size_t getExercisesCount() const {
        return exercises.size();
    }
    
    // Get exercise by index
    Exercise getExerciseByIndex(size_t index) const {
        if (index < exercises.size()) {
            return exercises[index];
        }
        // Return empty exercise if index is out of bounds
        return Exercise();
    }
};

// ====== Workout Plan Class ======
class WorkoutPlan {
private:
    string name;
    string description;
    string difficulty;  // "Beginner", "Intermediate", "Advanced"
    vector<pair<string, int>> exercises; // Exercise name and duration in minutes
    int totalDuration;
    double totalCalories;
    
public:
    WorkoutPlan() : totalDuration(0), totalCalories(0) {}
    
    WorkoutPlan(string _name, string _description, string _difficulty)
        : name(_name), description(_description), difficulty(_difficulty), totalDuration(0), totalCalories(0) {}
    
    // Add exercise to plan
    void addExercise(const string& exerciseName, int durationMin, double caloriesPerMin) {
        exercises.push_back(make_pair(exerciseName, durationMin));
        totalDuration += durationMin;
        totalCalories += durationMin * caloriesPerMin;
    }
    
    // Display workout plan
    void displayPlan() const {
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║                 🏋️ WORKOUT PLAN                  ║\n";
        cout << "╠══════════════════════════════════════════════════╣\n";
        cout << "║ Name: " << name << string(45 - name.length(), ' ') << "║\n";
        cout << "║ Description: " << description << string(38 - description.length(), ' ') << "║\n";
        cout << "║ Difficulty: " << difficulty << string(39 - difficulty.length(), ' ') << "║\n";
        cout << "║ Total Duration: " << totalDuration << " minutes" << string(34 - to_string(totalDuration).length(), ' ') << "║\n";
        cout << "║ Calories Burned: " << totalCalories << " kcal" << string(33 - doubleToString(totalCalories).length(), ' ') << "║\n";
        cout << "╠══════════════════════════════════════════════════╣\n";
        cout << "║ Exercise Plan:                                   ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        
        for (size_t i = 0; i < exercises.size(); i++) {
            cout << " " << (i + 1) << ". " << exercises[i].first << " - " << exercises[i].second << " minutes\n";
        }
    }
    
    // Getters
    string getName() const { return name; }
    string getDescription() const { return description; }
    string getDifficulty() const { return difficulty; }
    int getTotalDuration() const { return totalDuration; }
    double getTotalCalories() const { return totalCalories; }
    vector<pair<string, int>> getExercises() const { return exercises; }
};

// ====== Workout Plan Generator Class ======
class WorkoutPlanGenerator {
private:
    ExerciseManager* exerciseManager;
    
public:
    WorkoutPlanGenerator(ExerciseManager* _exerciseManager) : exerciseManager(_exerciseManager) {}
    
    // Generate a workout plan based on user preferences
    WorkoutPlan generatePlan(const string& fitnessLevel, int targetDuration, const string& focusArea) {
        try {
            // Validate inputs
            if (fitnessLevel.empty() || focusArea.empty() || targetDuration <= 0) {
                throw invalid_argument("Invalid input parameters");
            }

            // Create planName with size check
            string planName = focusArea;
            if (planName.length() > 50) {  // Limit name length
                planName = planName.substr(0, 47) + "...";
            }
            planName += " Workout";

            // Create description with size check
            stringstream ss;
            ss << "A " << targetDuration << "-minute " << fitnessLevel << " workout focusing on " << focusArea;
            string description = ss.str();
            if (description.length() > 100) {  // Limit description length
                description = description.substr(0, 97) + "...";
            }

            // Create the plan with the generated strings
            WorkoutPlan plan(planName, description, fitnessLevel);
            
            int minDifficulty = 1;
            int maxDifficulty = 10;
            
            if (fitnessLevel == "Beginner") {
                maxDifficulty = 4;
            } else if (fitnessLevel == "Intermediate") {
                minDifficulty = 3;
                maxDifficulty = 7;
            } else if (fitnessLevel == "Advanced") {
                minDifficulty = 6;
            }
            
            vector<Exercise> suitableExercises;
            for (size_t i = 0; i < exerciseManager->getExercisesCount(); i++) {
                Exercise exercise = exerciseManager->getExerciseByIndex(i);
                int difficulty = exercise.getDifficulty();
                string muscleGroup = exercise.getMuscleGroup();
                
                if (difficulty >= minDifficulty && difficulty <= maxDifficulty &&
                    (focusArea == "Full Body" || muscleGroup.find(focusArea) != string::npos)) {
                    suitableExercises.push_back(exercise);
                }
            }
            
            if (suitableExercises.empty()) {
                cout << "\n⚠️ No suitable exercises found for the specified criteria.\n";
                cout << "Adding default exercises to your plan.\n";
                
                for (size_t i = 0; i < exerciseManager->getExercisesCount(); i++) {
                    Exercise exercise = exerciseManager->getExerciseByIndex(i);
                    if (exercise.getDifficulty() <= maxDifficulty) {
                        suitableExercises.push_back(exercise);
                    }
                    if (suitableExercises.size() >= 3) break;
                }
            }
            
            int remainingTime = targetDuration;
            int exercisesCount = min(4, static_cast<int>(suitableExercises.size()));
            
            for (int i = 0; i < exercisesCount && remainingTime > 0; i++) {
                int exerciseTime = remainingTime / (exercisesCount - i);
                remainingTime -= exerciseTime;
                plan.addExercise(suitableExercises[i].getName(), exerciseTime, 
                                suitableExercises[i].getCaloriesPerMinute());
            }
            
            return plan;
        } catch (const exception& e) {
            // Handle any errors gracefully
            cout << "\n❌ Error generating workout plan: " << e.what() << "\n";
            // Return a default plan
            return WorkoutPlan("Default Workout", "A basic workout plan", "Beginner");
        }
    }
};

// ====== Workout Session Class ======
class WorkoutSession {
private:
    User* user;
    Exercise* currentExercise;
    WorkoutPlan* currentPlan;
    int totalDuration;
    double totalCaloriesBurned;
    double totalCO2Saved;
    int intensity; // 1-10 scale
    string startTime;
    bool isActive;
    
public:
    WorkoutSession(User* _user) : user(_user), currentExercise(nullptr), currentPlan(nullptr),
                                totalDuration(0), totalCaloriesBurned(0), totalCO2Saved(0),
                                intensity(5), isActive(false) {}
    
    // Start a workout session with a specific exercise
    void startExerciseSession(Exercise* exercise, int exerciseIntensity) {
        if (exercise == nullptr) {
            cout << "\n❌ Invalid exercise selected!\n";
            return;
        }
        
        currentExercise = exercise;
        intensity = exerciseIntensity;
        startTime = getCurrentTime();
        isActive = true;
        
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║               🏃 WORKOUT STARTED                  ║\n";
        cout << "╠══════════════════════════════════════════════════╣\n";
        cout << "║ Exercise: " << currentExercise->getName() << string(41 - currentExercise->getName().length(), ' ') << "║\n";
        cout << "║ Intensity: " << intensity << "/10" << string(40 - to_string(intensity).length(), ' ') << "║\n";
        cout << "║ Start Time: " << startTime << string(40 - startTime.length(), ' ') << "║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        
        // Display motivational quote
        cout << "\n💪 " << getRandomMotivationalQuote() << "\n";
        
        // Show exercise steps
        vector<string> steps = currentExercise->getSteps();
        if (!steps.empty()) {
            cout << "\n📋 Follow these steps:\n";
            for (size_t i = 0; i < steps.size(); i++) {
                cout << " " << (i + 1) << ". " << steps[i] << "\n";
            }
        }
    }
    
    // Start a workout session with a workout plan
    void startPlanSession(WorkoutPlan* plan, int exerciseIntensity) {
        if (plan == nullptr) {
            cout << "\n❌ Invalid workout plan selected!\n";
            return;
        }
        
        currentPlan = plan;
        intensity = exerciseIntensity;
        startTime = getCurrentTime();
        isActive = true;
        
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║               🏃 WORKOUT STARTED                  ║\n";
        cout << "╠══════════════════════════════════════════════════╣\n";
        cout << "║ Plan: " << currentPlan->getName() << string(45 - currentPlan->getName().length(), ' ') << "║\n";
        cout << "║ Intensity: " << intensity << "/10" << string(40 - to_string(intensity).length(), ' ') << "║\n";
        cout << "║ Start Time: " << startTime << string(40 - startTime.length(), ' ') << "║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        
        // Display motivational quote
        cout << "\n💪 " << getRandomMotivationalQuote() << "\n";
        
        // Display plan details
        currentPlan->displayPlan();
    }
    
    // End the workout session
    void endSession(int actualDuration) {
        if (!isActive) {
            cout << "\n❌ No active workout session!\n";
            return;
        }
        
        totalDuration = actualDuration;
        
        // Calculate calories burned and CO2 saved based on exercise intensity and duration
        if (currentExercise != nullptr) {
            double intensityFactor = intensity / 5.0; // Scale intensity effect
            totalCaloriesBurned = currentExercise->getCaloriesPerMinute() * totalDuration * intensityFactor;
            totalCO2Saved = currentExercise->getCO2SavedPerMinute() * totalDuration;
            
            // Update user stats
            user->totalCalories += totalCaloriesBurned;
            user->totalCO2 += totalCO2Saved;
            user->streak++;
            user->maxStreak = max(user->streak, user->maxStreak);
            
            // Log workout
            user->logWorkout(currentExercise->getName(), totalDuration, intensity, totalCaloriesBurned);
            
            // Update personal best if applicable
            if (totalDuration > 0) {
                user->updatePersonalBest(currentExercise->getName(), totalDuration);
            }
            
            // Award points based on exercise and duration
            int pointsEarned = (currentExercise->getPointsReward() * totalDuration) / 10;
            pointsEarned = max(1, pointsEarned); // At least 1 point per workout
            user->addPoints(pointsEarned);
            
            // Check if user unlocked new exercises
            if (user->getPoints() >= 25) {
                user->unlockExercise("Running");
            }
            if (user->getPoints() >= 50) {
                user->unlockExercise("Cycling");
            }
            if (user->getPoints() >= 75) {
                user->unlockExercise("Jumping Jacks");
            }
            if (user->getPoints() >= 100) {
                user->unlockExercise("Plank");
            }
            if (user->getPoints() >= 125) {
                user->unlockExercise("Mountain Climbers");
            }
        } else if (currentPlan != nullptr) {
            // For workout plans, use the plan's total calories
            double intensityFactor = intensity / 5.0; // Scale intensity effect
            totalCaloriesBurned = currentPlan->getTotalCalories() * intensityFactor;
            
            // Estimate CO2 saved (could be more accurate with individual exercises)
            totalCO2Saved = totalCaloriesBurned * 0.3; // Rough estimation
            
            // Update user stats
            user->totalCalories += totalCaloriesBurned;
            user->totalCO2 += totalCO2Saved;
            user->streak++;
            user->maxStreak = max(user->streak, user->maxStreak);
            
            // Log workout
            user->logWorkout(currentPlan->getName(), totalDuration, intensity, totalCaloriesBurned);
            
            // Award points based on plan difficulty and duration
            int pointsBase = 5; // Base points
            if (currentPlan->getDifficulty() == "Intermediate") pointsBase = 8;
            else if (currentPlan->getDifficulty() == "Advanced") pointsBase = 12;
            
            int pointsEarned = (pointsBase * totalDuration) / 15;
            pointsEarned = max(3, pointsEarned); // At least 3 points for plan completion
            user->addPoints(pointsEarned);
        }
        
        displaySummary();
        
        // Reset session
        currentExercise = nullptr;
        currentPlan = nullptr;
        isActive = false;
    }
    
    // Display workout summary
    void displaySummary() const {
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════╗\n";
        cout << "║            🏆 WORKOUT SUMMARY                     ║\n";
        cout << "╠══════════════════════════════════════════════════╣\n";
        cout << "║ Duration: " << totalDuration << " minutes" << string(38 - to_string(totalDuration).length(), ' ') << "║\n";
        cout << "║ Calories Burned: " << totalCaloriesBurned << " kcal" << string(33 - doubleToString(totalCaloriesBurned).length(), ' ') << "║\n";
        cout << "║ CO₂ Saved: " << totalCO2Saved << " g" << string(38 - doubleToString(totalCO2Saved).length(), ' ') << "║\n";
        cout << "║ Current Streak: " << user->streak << " days" << string(34 - to_string(user->streak).length(), ' ') << "║\n";
        cout << "║ Total Points: " << user->getPoints() << string(37 - to_string(user->getPoints()).length(), ' ') << "║\n";
        cout << "╚══════════════════════════════════════════════════╝\n";
        
        // Show congratulatory message
        cout << "\n🎉 Great job! You've completed your workout!\n";
    }
    
    // Check if session is active
    bool isSessionActive() const {
        return isActive;
    }
};
// ====== Main Function ======
int main() {
    cout << "\n";
        cout << "╔════════════════════════════════════════════════════════════╗\n";
        cout << "║                                                            ║\n";
        cout << "║   ███████╗██╗████████╗███╗   ██╗███████╗███████╗███████╗   ║\n";
        cout << "║   ██╔════╝██║╚══██╔══╝████╗  ██║██╔════╝██╔════╝██╔════╝   ║\n";
        cout << "║   █████╗  ██║   ██║   ██╔██╗ ██║█████╗  ███████╗███████╗   ║\n";
        cout << "║   ██╔══╝  ██║   ██║   ██║╚██╗██║██╔══╝  ╚════██║╚════██║   ║\n";
        cout << "║   ██║     ██║   ██║   ██║ ╚████║███████╗███████║███████║   ║\n";
        cout << "║   ╚═╝     ╚═╝   ╚═╝   ╚═╝  ╚═══╝╚══════╝╚══════╝╚══════╝   ║\n";
        cout << "║                                                            ║\n";
        cout << "║                    FITNESS TRACKER APP                     ║\n";
        cout << "║             Version 1.0 - By   Waqar Anas Tuheed           ║\n";
        cout << "║                                                            ║\n";
        cout << "╚════════════════════════════════════════════════════════════╝\n";
        cout << "\n";
    
    // Initialize system components
    LoginSystem loginSystem;
    ExerciseManager exerciseManager;
    WorkoutPlanGenerator planGenerator(&exerciseManager);
    Leaderboard leaderboard;
    
    User currentUser;
    bool isLoggedIn = false;
    WorkoutSession* activeSession = nullptr;
    
    // Main application loop
    bool exitApp = false;
    while (!exitApp) {
        if (!isLoggedIn) {
            // Login/Registration Menu
            cout << "\n";
            cout << "╔══════════════════════════════════════════════════╗\n";
            cout << "║                📝 WELCOME MENU                            ║\n";
            cout << "╠══════════════════════════════════════════════════╣\n";
            cout << "║ 1. Login                                                  ║\n";
            cout << "║ 2. Register                                               ║\n";
            cout << "║ 3. Reset Password                                         ║\n";
            cout << "║ 4. View Leaderboard                                       ║\n";
            cout << "║ 5. Exit Application                                       ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n";
            cout << "\nEnter your choice: ";
            
            int choice;
            cin >> choice;
            cin.ignore(); // Clear input buffer
            
            string username, password, newPassword, background;
            
            switch (choice) {
                case 1: // Login
                    cout << "\nEnter username: ";
                    getline(cin, username);
                    cout << "Enter password: ";
                    getline(cin, password);
                    
                    if (loginSystem.login(username, password, currentUser)) {
                        isLoggedIn = true;
                        cout << "\n✅ Login successful! Welcome back, " << currentUser.getUsername() << "!\n";
                        
                        // Show a motivational quote upon login
                        cout << "\n💪 " << getRandomMotivationalQuote() << "\n";
                    } else {
                        cout << "\n❌ Login failed! Invalid username or password.\n";
                    }
                    break;
                    
                case 2: // Register
                    cout << "\nEnter new username: ";
                    getline(cin, username);
                    cout << "Enter new password: ";
                    getline(cin, password);
                    cout << "Enter your fitness background: ";
                    getline(cin, background);
                    
                    loginSystem.registerUser(username, password, background);
                    break;
                    
                case 3: // Reset Password
                    cout << "\nEnter username: ";
                    getline(cin, username);
                    cout << "Enter new password: ";
                    getline(cin, newPassword);
                    
                    if (loginSystem.resetPassword(username, newPassword)) {
                        cout << "\n✅ Password reset successful! Please login with your new password.\n";
                    } else {
                        cout << "\n❌ Password reset failed! User not found.\n";
                    }
                    break;
                    
                case 4: // View Leaderboard
                    leaderboard.updateLeaderboard(loginSystem.getUsers());
                    break;
                    
                case 5: // Exit Application
                    cout << "\n👋 Thank you for using Fitness Tracker App! Goodbye!\n";
                    exitApp = true;
                    break;
                    
                default:
                    cout << "\n❌ Invalid choice! Please try again.\n";
                    break;
            }
        } else {
            // Main Menu for logged-in users
            cout << "\n";
            cout << "╔══════════════════════════════════════════════════╗\n";
            cout << "║                🏋️ MAIN MENU                               ║\n";
            cout << "╠══════════════════════════════════════════════════╣\n";
            cout << "║ 1. View Profile                                           ║\n";
            cout << "║ 2. Update Profile                                         ║\n";
            cout << "║ 3. Start Exercise Session                                 ║\n";
            cout << "║ 4. Generate Workout Plan                                  ║\n";
            cout << "║ 5. View Exercise Library                                  ║\n";
            cout << "║ 6. View Workout History                                   ║\n";
            cout << "║ 7. View Goals                                             ║\n";
            cout << "║ 8. Add Goal                                               ║\n";
            cout << "║ 9. View Personal Bests                                    ║\n";
            cout << "║ 10. View Leaderboard                                      ║\n";
            cout << "║ 11. Change Password                                       ║\n";
            cout << "║ 12. Logout                                                ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n";
            cout << "\nEnter your choice: ";
            
            int choice;
            cin >> choice;
            cin.ignore(); // Clear input buffer
            
            switch (choice) {
                case 1: // View Profile
                    currentUser.displayProfile();
                    break;
                    
                case 2: // Update Profile
                    {
                        cout << "\n";
                        cout << "╔══════════════════════════════════════════════════╗\n";
                        cout << "║              ✏️ UPDATE PROFILE                    ║\n";
                        cout << "╠══════════════════════════════════════════════════╣\n";
                        cout << "║ 1. Update Weight                                 ║\n";
                        cout << "║ 2. Update Height                                 ║\n";
                        cout << "║ 3. Update Age                                    ║\n";
                        cout << "║ 4. Update Background                             ║\n";
                        cout << "║ 5. Back to Main Menu                             ║\n";
                        cout << "╚══════════════════════════════════════════════════╝\n";
                        cout << "\nEnter your choice: ";
                        
                        int updateChoice;
                        cin >> updateChoice;
                        cin.ignore(); // Clear input buffer
                        
                        string newBackground;
                        double newValue;
                        int newAge;
                        
                        switch (updateChoice) {
                            case 1: // Update Weight
                                cout << "Enter your weight (kg): ";
                                cin >> newValue;
                                currentUser.setWeight(newValue);
                                cout << "\n✅ Weight updated successfully!\n";
                                break;
                                
                            case 2: // Update Height
                                cout << "Enter your height (m): ";
                                cin >> newValue;
                                currentUser.setHeight(newValue);
                                cout << "\n✅ Height updated successfully!\n";
                                break;
                                
                            case 3: // Update Age
                                cout << "Enter your age: ";
                                cin >> newAge;
                                currentUser.setAge(newAge);
                                cout << "\n✅ Age updated successfully!\n";
                                break;
                                
                            case 4: // Update Background
                                cout << "Enter your fitness background: ";
                                getline(cin, newBackground);
                                currentUser.background = newBackground;
                                cout << "\n✅ Background updated successfully!\n";
                                break;
                                
                            case 5: // Back to Main Menu
                                break;
                                
                            default:
                                cout << "\n❌ Invalid choice! Please try again.\n";
                                break;
                        }
                        
                        // Save changes
                        loginSystem.updateUser(currentUser);
                    }
                    break;
                    
                case 3: // Start Exercise Session
                    {
                        // Check if there's already an active session
                        if (activeSession != nullptr && activeSession->isSessionActive()) {
                            cout << "\n⚠️ You already have an active workout session. End it first!\n";
                            break;
                        }
                        
                        cout << "\n";
                        cout << "╔══════════════════════════════════════════════════╗\n";
                        cout << "║             🏃 START WORKOUT                      ║\n";
                        cout << "╠══════════════════════════════════════════════════╣\n";
                        cout << "║ 1. Start Individual Exercise                     ║\n";
                        cout << "║ 2. Start Workout Plan                            ║\n";
                        cout << "║ 3. Back to Main Menu                             ║\n";
                        cout << "╚══════════════════════════════════════════════════╝\n";
                        cout << "\nEnter your choice: ";
                        
                        int workoutChoice;
                        cin >> workoutChoice;
                        cin.ignore(); // Clear input buffer
                        
                        switch (workoutChoice) {
                            case 1: // Start Individual Exercise
                                {
                                    // Display available exercises
                                    currentUser.displayLockedExercises();
                                    cout << "\n🔓 Your Unlocked Exercises:\n";
                                    for (size_t i = 0; i < currentUser.unlockedExercises.size(); i++) {
                                        cout << " " << (i + 1) << ". " << currentUser.unlockedExercises[i] << "\n";
                                    }
                                    
                                    cout << "\nEnter exercise number: ";
                                    int exerciseNumber;
                                    cin >> exerciseNumber;
                                    
                                    if (exerciseNumber > 0 && exerciseNumber <= static_cast<int>(currentUser.unlockedExercises.size())) {
                                        string exerciseName = currentUser.unlockedExercises[exerciseNumber - 1];
                                        Exercise* selectedExercise = exerciseManager.getExerciseByName(exerciseName);
                                        
                                        if (selectedExercise != nullptr) {
                                            // Display exercise details
                                            selectedExercise->displayInfo();
                                            
                                            // Get exercise intensity
                                            cout << "\nEnter intensity (1-10): ";
                                            int intensity;
                                            cin >> intensity;
                                            intensity = max(1, min(10, intensity)); // Ensure valid range
                                            
                                            // Create and start session
                                            if (activeSession == nullptr) {
                                                activeSession = new WorkoutSession(&currentUser);
                                            }
                                            activeSession->startExerciseSession(selectedExercise, intensity);
                                            
                                            // Simulate workout
                                            cout << "\n⏳ Simulating workout session...\n";
                                            manualSleep(2); // Sleep for 2 seconds to simulate workout
                                            
                                            // End session
                                            cout << "\nEnter actual duration (minutes): ";
                                            int duration;
                                            cin >> duration;
                                            activeSession->endSession(duration);
                                            
                                            // Update user in login system to save changes
                                            loginSystem.updateUser(currentUser);
                                        } else {
                                            cout << "\n❌ Exercise not found!\n";
                                        }
                                    } else {
                                        cout << "\n❌ Invalid exercise number!\n";
                                    }
                                }
                                break;
                                
                            case 2: // Start Workout Plan
                                {
                                    cout << "\nGenerating workout plan based on your profile...\n";
                                    
                                    // Get plan parameters
                                    cout << "\nEnter desired workout duration (minutes): ";
                                    int duration;
                                    cin >> duration;
                                    cin.ignore(); // Clear input buffer
                                    
                                    cout << "Enter focus area (e.g., Cardio, Chest, Legs, Full Body): ";
                                    string focusArea;
                                    getline(cin, focusArea);
                                    
                                    // Generate workout plan
                                    WorkoutPlan plan = planGenerator.generatePlan(currentUser.fitnessLevel, duration, focusArea);
                                    
                                    // Display plan
                                    plan.displayPlan();
                                    
                                    // Ask if user wants to start this plan
                                    cout << "\nStart this workout plan? (1: Yes, 2: No): ";
                                    int startPlan;
                                    cin >> startPlan;
                                    
                                    if (startPlan == 1) {
                                        // Get exercise intensity
                                        cout << "\nEnter intensity (1-10): ";
                                        int intensity;
                                        cin >> intensity;
                                        intensity = max(1, min(10, intensity)); // Ensure valid range
                                        
                                        // Create and start session
                                        if (activeSession == nullptr) {
                                            activeSession = new WorkoutSession(&currentUser);
                                        }
                                        activeSession->startPlanSession(&plan, intensity);
                                        
                                        // Simulate workout
                                        cout << "\n⏳ Simulating workout session...\n";
                                        manualSleep(2); // Sleep for 2 seconds to simulate workout
                                        
                                        // End session
                                        cout << "\nEnter actual duration (minutes): ";
                                        int actualDuration;
                                        cin >> actualDuration;
                                        activeSession->endSession(actualDuration);
                                        
                                        // Update user in login system to save changes
                                        loginSystem.updateUser(currentUser);
                                    }
                                }
                                break;
                                
                            case 3: // Back to Main Menu
                                break;
                                
                            default:
                                cout << "\n❌ Invalid choice! Please try again.\n";
                                break;
                        }
                    }
                    break;
                    
                case 4: // Generate Workout Plan
                    {
                        cout << "\n";
                        cout << "╔══════════════════════════════════════════════════╗\n";
                        cout << "║           📋 GENERATE WORKOUT PLAN                ║\n";
                        cout << "╚══════════════════════════════════════════════════╝\n";
                        
                        // Get plan parameters
                        cout << "\nEnter desired workout duration (minutes): ";
                        int duration;
                        cin >> duration;
                        cin.ignore(); // Clear input buffer
                        
                        cout << "Enter focus area (e.g., Cardio, Chest, Legs, Full Body): ";
                        string focusArea;
                        getline(cin, focusArea);
                        
                        // Generate workout plan
                        WorkoutPlan plan = planGenerator.generatePlan(currentUser.fitnessLevel, duration, focusArea);
                        
                        // Display plan
                        plan.displayPlan();
                    }
                    break;
                    
                case 5: // View Exercise Library
                    {
                        cout << "\n";
                        cout << "╔══════════════════════════════════════════════════╗\n";
                        cout << "║           📚 EXERCISE LIBRARY                     ║\n";
                        cout << "╠══════════════════════════════════════════════════╣\n";
                        cout << "║ 1. View All Exercises                            ║\n";
                        cout << "║ 2. Search by Muscle Group                        ║\n";
                        cout << "║ 3. Filter by Difficulty                          ║\n";
                        cout << "║ 4. Back to Main Menu                             ║\n";
                        cout << "╚══════════════════════════════════════════════════╝\n";
                        cout << "\nEnter your choice: ";
                        
                        int libraryChoice;
                        cin >> libraryChoice;
                        cin.ignore(); // Clear input buffer
                        
                        switch (libraryChoice) {
                            case 1: // View All Exercises
                                exerciseManager.displayAllExercises();
                                break;
                                
                            case 2: // Search by Muscle Group
                                {
                                    cout << "\nEnter muscle group (e.g., Chest, Legs, Core): ";
                                    string muscleGroup;
                                    getline(cin, muscleGroup);
                                    exerciseManager.displayExercisesByMuscleGroup(muscleGroup);
                                }
                                break;
                                
                            case 3: // Filter by Difficulty
                                {
                                    cout << "\nEnter minimum difficulty (1-10): ";
                                    int minDifficulty;
                                    cin >> minDifficulty;
                                    
                                    cout << "Enter maximum difficulty (1-10): ";
                                    int maxDifficulty;
                                    cin >> maxDifficulty;
                                    
                                    exerciseManager.displayExercisesByDifficulty(minDifficulty, maxDifficulty);
                                }
                                break;
                                
                            case 4: // Back to Main Menu
                                break;
                                
                            default:
                                cout << "\n❌ Invalid choice! Please try again.\n";
                                break;
                        }
                    }
                    break;
                    
                case 6: // View Workout History
                    currentUser.displayWorkoutHistory();
                    break;
                    
                case 7: // View Goals
                    currentUser.displayGoals();
                    break;
                    
                case 8: // Add Goal
                    {
                        cout << "\nEnter your new fitness goal: ";
                        string goal;
                        getline(cin, goal);
                        
                        currentUser.addGoal(goal);
                        loginSystem.updateUser(currentUser); // Save changes
                    }
                    break;
                    
                case 9: // View Personal Bests
                    currentUser.displayPersonalBests();
                    break;
                    
                case 10: // View Leaderboard
                    leaderboard.updateLeaderboard(loginSystem.getUsers());
                    break;
                    
                case 11: // Change Password
                    {
                        string oldPassword, newPassword;
                        cout << "\nEnter current password: ";
                        getline(cin, oldPassword);
                        cout << "Enter new password: ";
                        getline(cin, newPassword);
                        
                        if (loginSystem.changePassword(currentUser.getUsername(), oldPassword, newPassword)) {
                            cout << "\n✅ Password changed successfully!\n";
                        } else {
                            cout << "\n❌ Password change failed! Incorrect current password.\n";
                        }
                    }
                    break;
                    
                case 12: // Logout
                    cout << "\n✅ Logged out successfully!\n";
                    isLoggedIn = false;
                    
                    // Clean up active session if any
                    if (activeSession != nullptr) {
                        delete activeSession;
                        activeSession = nullptr;
                    }
                    break;
                    
                default:
                    cout << "\n❌ Invalid choice! Please try again.\n";
                    break;
            }
        }
    }
    
    // Clean up active session if any
    if (activeSession != nullptr) {
        delete activeSession;
    }
    
    return 0;
}