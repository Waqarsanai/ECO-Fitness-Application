const import_cpp = {
            my_namespace: { import_cpp: (Project) => console.log(Project) },
        };

        fetch('http://lookup-service-APIDOG.com/json/named.work_outs?users?le_Sqsapp.fitnessapp?Project.cpp_code=uein_dcmdc"ooo-9232320jf22"-https://--go_cpp./fitnessapp.com')
        
        .then(response => response.json())
        .then(data => {
            console.log(data);
        })
        .catch(error => {
            console.error('Error fetching data:', error);
        });


        // DOM elements for screen navigation
const screens = {};

// Helper function to safely get DOM elements with error handling
function safeGetElement(id) {
    const element = document.getElementById(id);
    if (!element) {
        console.warn(`Element with ID '${id}' not found in the document.`);
    }
    return element;
}

// Initialize all screen elements safely
function initScreens() {
    const screenIds = [
        'welcome-screen', 'login-form', 'register-form', 'reset-form',
        'leaderboard', 'main-app', 'profile-view', 'update-profile',
        'start-workout', 'individual-exercise', 'exercise-detail', 'active-workout',
        'end-workout', 'workout-plan', 'generated-plan', 'exercise-library',
        'all-exercises', 'workout-history', 'goals', 'current-goals',
        'set-goal', 'personal-bests', 'change-password'
    ];

    // Convert camelCase keys to kebab-case for DOM IDs
    const screenMap = {
        welcomeScreen: 'welcome-screen',
        loginForm: 'login-form',
        registerForm: 'register-form',
        resetForm: 'reset-form',
        leaderboard: 'leaderboard',
        mainApp: 'main-app',
        profileView: 'profile-view',
        updateProfile: 'update-profile',
        startWorkout: 'start-workout',
        individualExercise: 'individual-exercise',
        exerciseDetail: 'exercise-detail',
        activeWorkout: 'active-workout',
        endWorkout: 'end-workout',
        workoutPlan: 'workout-plan',
        generatedPlan: 'generated-plan',
        exerciseLibrary: 'exercise-library',
        allExercises: 'all-exercises',
        workoutHistory: 'workout-history',
        goals: 'goals',
        currentGoals: 'current-goals',
        setGoal: 'set-goal',
        personalBests: 'personal-bests',
        changePassword: 'change-password'
    };

    // Initialize screens object with actual DOM elements
    for (const [key, id] of Object.entries(screenMap)) {
        screens[key] = safeGetElement(id);
    }
}

// User data store (simulated database)
let currentUser = null;
const users = [
    {
        username: 'Waqar',
        password: 'w123',
        background: 'Athlete',
        level: 'Advanced',
        streak: 14,
        maxStreak: 21,
        badge: '🏅 Intermediate',
        points: 26,
        loginStreak: 7,
        weight: 75,
        height: 1.78,
        bmi: '23.7 (Normal)',
        totalCalories: 12450,
        co2Saved: 3735,
        unlockedExercises: ['Push-ups', 'Squats', 'Running']
    },
    {
        username: 'Anas',
        password: 'a123',
        background: 'Beginner',
        level: 'Beginner',
        streak: 3,
        maxStreak: 3,
        badge: '🏅 Intermediate',
        points: 25,
        loginStreak: 3,
        weight: 70,
        height: 1.70,
        bmi: '24.2 (Normal)',
        totalCalories: 950,
        co2Saved: 285,
        unlockedExercises: ['Push-ups', 'Squats', 'Running']
    }, {
        username: 'Tuheed',
        password: 't123',
        background: 'Beginner',
        level: 'Beginner',
        streak: 3,
        maxStreak: 3,
        badge: '🏅 Intermediate',
        points: 25,
        loginStreak: 3,
        weight: 70,
        height: 1.70,
        bmi: '24.2 (Normal)',
        totalCalories: 950,
        co2Saved: 285,
        unlockedExercises: ['Push-ups', 'Squats', 'Running']
    }
];

// Exercise data
const exercises = [
    {
        name: 'Push-ups',
        category: 'Upper body strength',
        difficulty: 'Intermediate',
        caloriesPerMin: 8,
        co2SavedPerMin: 2.5,
        pointsReward: 5,
        muscleGroup: 'Chest, Triceps, Shoulders',
        steps: [
            'Start in a plank position with hands slightly wider than shoulder-width.',
            'Lower your body until your chest nearly touches the floor.',
            'Push yourself back up to the starting position.',
            'Keep your core tight and back straight throughout the movement.'
        ]
    },
    {
        name: 'Squats',
        category: 'Lower body strength',
        difficulty: 'Beginner',
        caloriesPerMin: 8,
        co2SavedPerMin: 2.4,
        pointsReward: 5,
        muscleGroup: 'Quadriceps, Hamstrings, Glutes',
        steps: [
            'Stand with feet shoulder-width apart.',
            'Lower your body by bending your knees and pushing your hips back.',
            'Go down until thighs are parallel to the ground.',
            'Push back up to starting position.'
        ]
    },
    {
        name: 'Running',
        category: 'Cardiovascular',
        difficulty: 'Beginner',
        caloriesPerMin: 9,
        co2SavedPerMin: 2.7,
        pointsReward: 6,
        muscleGroup: 'Full body, emphasis on legs',
        steps: [
            'Start with a warm-up walk for 2-3 minutes.',
            'Gradually increase to a comfortable jogging pace.',
            'Maintain proper posture with shoulders relaxed.',
            'Land midfoot and keep a steady breathing rhythm.',
            'Cool down with a walk for 2-3 minutes at the end.'
        ]
    }
];

// Workout history
const workoutHistory = [
    { date: '2023-05-15', exercise: 'Push-ups', duration: '15 min', calories: '120 kcal', points: 8 },
    { date: '2023-05-14', exercise: 'Running', duration: '20 min', calories: '180 kcal', points: 10 },
    { date: '2023-05-13', exercise: 'Squats', duration: '10 min', calories: '80 kcal', points: 5 },
    { date: '2023-05-12', exercise: 'Plank', duration: '5 min', calories: '40 kcal', points: 3 },
    { date: '2023-05-11', exercise: 'Push-ups', duration: '12 min', calories: '96 kcal', points: 6 }
];

// Goals data
const goals = [
    { title: '30 Push-ups in a Row', current: '22/30', progress: 73, due: '2023-06-15' },
    { title: 'Run 5km in 25 Minutes', current: '28 minutes', progress: 45, due: '2023-07-01' },
    { title: 'Exercise 5 Days a Week', current: '4/5 days', progress: 80, due: 'Weekly goal' }
];

// Personal bests
const personalBests = [
    { exercise: 'Push-ups', record: '22 in a row', date: '2023-05-15' },
    { exercise: 'Running', record: '28 min (5km)', date: '2023-05-14' },
    { exercise: 'Squats', record: '50 in a row', date: '2023-05-13' },
    { exercise: 'Plank', record: '3 minutes', date: '2023-05-12' }
];

// Utility functions
function showScreen(screenId) {
    console.log(`Attempting to show screen: ${screenId}`);
    
    // Hide all screens
    Object.values(screens).forEach(screen => {
        if (screen) screen.classList.add('hidden');
    });
    
    // Show requested screen
    const screen = screens[screenId];
    if (screen) {
        screen.classList.remove('hidden');
        console.log(`Successfully shown screen: ${screenId}`);
    } else {
        console.error(`Failed to show screen: ${screenId} - Element not found`);
    }
    
    // Update leaderboard if showing leaderboard screen
    if (screenId === 'leaderboard') {
        populateLeaderboard();
    }
    
    // Update profile view if showing profile screen
    if (screenId === 'profileView') {
        updateProfileView();
    }
}

function formatTime(seconds) {
    const hrs = Math.floor(seconds / 3600);
    const mins = Math.floor((seconds % 3600) / 60);
    const secs = seconds % 60;
    
    return `${hrs.toString().padStart(2, '0')}:${mins.toString().padStart(2, '0')}:${secs.toString().padStart(2, '0')}`;
}

function updateProfileView() {
    if (currentUser) {
        safeUpdateTextContent('logged-in-username', currentUser.username);
        safeUpdateTextContent('profile-username', currentUser.username);
        safeUpdateTextContent('profile-background', currentUser.background);
        safeUpdateTextContent('profile-level', currentUser.level);
        safeUpdateTextContent('profile-streak', `${currentUser.streak} days`);
        safeUpdateTextContent('profile-max-streak', `${currentUser.maxStreak} days`);
        safeUpdateTextContent('profile-badge', currentUser.badge);
        safeUpdateTextContent('profile-points', currentUser.points);
        safeUpdateTextContent('profile-login-streak', `${currentUser.loginStreak} days`);
        safeUpdateTextContent('profile-weight', `${currentUser.weight} kg`);
        safeUpdateTextContent('profile-height', `${currentUser.height} m`);
        safeUpdateTextContent('profile-bmi', currentUser.bmi);
        safeUpdateTextContent('profile-calories', `${currentUser.totalCalories} kcal`);
        safeUpdateTextContent('profile-co2', `${currentUser.co2Saved} g`);
        safeUpdateTextContent('profile-exercises', currentUser.unlockedExercises.join(', '));
    }
}

// Helper function to safely update text content
function safeUpdateTextContent(id, text) {
    const element = document.getElementById(id);
    if (element) {
        element.textContent = text;
    } else {
        console.warn(`Element with ID '${id}' not found when updating text content.`);
    }
}

// Update badge based on points
function updateUserBadge() {
    if (!currentUser) return;
    
    // Update badge based on points
    if (currentUser.points >= 150) {
        currentUser.badge = '🌟 Legend';
        currentUser.level = 'Advanced';
    } else if (currentUser.points >= 75) {
        currentUser.badge = '🎖️ Expert';
        currentUser.level = 'Intermediate';
    } else if (currentUser.points >= 30) {
        currentUser.badge = '🏅 Intermediate';
        currentUser.level = 'Intermediate';
    } else {
        currentUser.badge = '🏅 Beginner';
        currentUser.level = 'Beginner';
    }
}

// Safely add event listener
function safeAddEventListener(id, event, handler) {
    const element = document.getElementById(id);
    if (element) {
        element.addEventListener(event, handler);
        return true;
    } else {
        console.warn(`Cannot add event listener to element with ID '${id}' - element not found.`);
        return false;
    }
}

// Initialize event listeners
function initEventListeners() {
    console.log("Initializing event listeners...");
    
    // Welcome screen buttons
    safeAddEventListener('login-btn', 'click', () => showScreen('loginForm'));
    safeAddEventListener('register-btn', 'click', () => showScreen('registerForm'));
    safeAddEventListener('reset-btn', 'click', () => showScreen('resetForm'));
    safeAddEventListener('leaderboard-btn', 'click', () => showScreen('leaderboard'));
    
    // Login form
    safeAddEventListener('login-submit', 'click', handleLogin);
    safeAddEventListener('login-cancel', 'click', () => showScreen('welcomeScreen'));
    
    // Register form
    safeAddEventListener('register-submit', 'click', handleRegister);
    safeAddEventListener('register-cancel', 'click', () => showScreen('welcomeScreen'));
    
    // Reset password form
    safeAddEventListener('reset-submit', 'click', handleResetPassword);
    safeAddEventListener('reset-cancel', 'click', () => showScreen('welcomeScreen'));
    
    // Leaderboard back button
    safeAddEventListener('leaderboard-back', 'click', () => {
        if (currentUser) {
            showScreen('mainApp');
        } else {
            showScreen('welcomeScreen');
        }
    });
    
    // Main menu buttons
    safeAddEventListener('profile-btn', 'click', () => {
        updateProfileView();
        showScreen('profileView');
    });
    safeAddEventListener('update-profile-btn', 'click', () => {
        // Pre-fill form with current user data
        if (currentUser) {
            const usernameInput = document.getElementById('update-username');
            const weightInput = document.getElementById('update-weight');
            const heightInput = document.getElementById('update-height');
            const backgroundInput = document.getElementById('update-background');
            
            if (usernameInput) usernameInput.value = currentUser.username;
            if (weightInput) weightInput.value = currentUser.weight;
            if (heightInput) heightInput.value = currentUser.height;
            if (backgroundInput) backgroundInput.value = currentUser.background;
        }
        showScreen('updateProfile');
    });
    
    // Update profile form
    safeAddEventListener('save-profile-btn', 'click', saveProfileChanges);
    
    safeAddEventListener('workout-btn', 'click', () => showScreen('startWorkout'));
    safeAddEventListener('library-btn', 'click', () => showScreen('exerciseLibrary'));
    safeAddEventListener('history-btn', 'click', () => showScreen('workoutHistory'));
    safeAddEventListener('goals-btn', 'click', () => showScreen('goals'));
    safeAddEventListener('bests-btn', 'click', () => showScreen('personalBests'));
    safeAddEventListener('app-leaderboard-btn', 'click', () => showScreen('leaderboard'));
    safeAddEventListener('change-password-btn', 'click', () => showScreen('changePassword'));
    safeAddEventListener('logout-btn', 'click', handleLogout);
    
    // Profile view back button
    safeAddEventListener('profile-back', 'click', () => showScreen('mainApp'));
    
    // Update profile back button
    safeAddEventListener('update-profile-back', 'click', () => showScreen('mainApp'));
    
    // Start workout buttons
    safeAddEventListener('start-workout-back', 'click', () => showScreen('mainApp'));
    safeAddEventListener('individual-exercise-btn', 'click', () => showScreen('individualExercise'));
    safeAddEventListener('workout-plan-btn', 'click', () => showScreen('workoutPlan'));
    
    // Individual exercise back button
    safeAddEventListener('individual-exercise-back', 'click', () => showScreen('startWorkout'));
    
    // Exercise library buttons
    safeAddEventListener('exercise-library-back', 'click', () => showScreen('mainApp'));
    safeAddEventListener('all-exercises-btn', 'click', () => showScreen('allExercises'));
    
    // All exercises back button
    safeAddEventListener('all-exercises-back', 'click', () => showScreen('exerciseLibrary'));
    
    // Exercise detail setup
    const exerciseLinks = document.querySelectorAll('.menu-item a.btn');
    exerciseLinks.forEach(link => {
        if (link && link.parentElement && link.parentElement.querySelector('h3')) {
            const exerciseName = link.parentElement.querySelector('h3').textContent;
            if (['Push-ups', 'Squats', 'Running'].includes(exerciseName)) {
                link.addEventListener('click', (e) => {
                    e.preventDefault();
                    const exercise = exercises.find(ex => ex.name === exerciseName);
                    if (exercise) {
                        setupExerciseDetail(exercise);
                        showScreen('exerciseDetail');
                    }
                });
            }
        }
    });
    
    // Exercise detail back button
    safeAddEventListener('exercise-detail-back', 'click', () => showScreen('individualExercise'));
    
    // Start exercise button
    safeAddEventListener('start-exercise-btn', 'click', startExerciseSession);
    
    // End workout button
    safeAddEventListener('end-workout-btn', 'click', endWorkoutSession);
    
    // End workout back button
    safeAddEventListener('end-workout-back', 'click', () => {
        showScreen('mainApp');
        // Update leaderboard after workout
        populateLeaderboard();
    });
    
    // Workout plan buttons
    safeAddEventListener('workout-plan-back', 'click', () => showScreen('startWorkout'));
    safeAddEventListener('generate-plan-btn', 'click', generateWorkoutPlan);
    
    // Generated plan buttons
    safeAddEventListener('generated-plan-back', 'click', () => showScreen('workoutPlan'));
    safeAddEventListener('start-plan-btn', 'click', startPlanSession);
    
    // Workout history back button
    safeAddEventListener('workout-history-back', 'click', () => showScreen('mainApp'));
    
    // Goals buttons
    safeAddEventListener('goals-back', 'click', () => showScreen('mainApp'));
    safeAddEventListener('current-goals-btn', 'click', () => showScreen('currentGoals'));
    safeAddEventListener('set-goal-btn', 'click', () => showScreen('setGoal'));
    
    // Current goals back button
    safeAddEventListener('current-goals-back', 'click', () => showScreen('goals'));
    
    // Set goal buttons
    safeAddEventListener('set-goal-back', 'click', () => showScreen('goals'));
    safeAddEventListener('save-goal-btn', 'click', saveGoal);
    
    // Personal bests back button
    safeAddEventListener('personal-bests-back', 'click', () => showScreen('mainApp'));
    
    // Change password buttons
    safeAddEventListener('change-password-back', 'click', () => showScreen('mainApp'));
    safeAddEventListener('change-password-submit', 'click', changePassword);
    
    console.log("Event listeners initialized");
}

// Login handler
function handleLogin() {
    console.log("Login attempt");
    const usernameInput = document.getElementById('login-username');
    const passwordInput = document.getElementById('login-password');
    
    if (!usernameInput || !passwordInput) {
        alert('Login form elements not found!');
        return;
    }
    
    const username = usernameInput.value.toLowerCase();
    const password = passwordInput.value;
    
    const user = users.find(u => u.username.toLowerCase() === username && u.password === password);
    
    if (user) {
        currentUser = user;
        safeUpdateTextContent('logged-in-username', user.username);
        showScreen('mainApp');
        // Clear login form
        usernameInput.value = '';
        passwordInput.value = '';
        console.log("Login successful:", username);
    } else {
        alert('Invalid username or password!');
        console.log("Login failed:", username);
    }
}

// Register handler
function handleRegister() {
    console.log("Register attempt");
    const usernameInput = document.getElementById('register-username');
    const passwordInput = document.getElementById('register-password');
    const backgroundInput = document.getElementById('register-background');
    
    if (!usernameInput || !passwordInput) {
        alert('Register form elements not found!');
        return;
    }
    
    const username = usernameInput.value;
    const password = passwordInput.value;
    const background = backgroundInput ? backgroundInput.value : 'Beginner';
    
    if (!username || !password) {
        alert('Please fill in all required fields!');
        return;
    }
    
    if (users.some(u => u.username.toLowerCase() === username.toLowerCase())) {
        alert('Username already exists!');
        return;
    }
    
    const newUser = {
        username: username,
        password: password,
        background: background || 'Beginner',
        level: 'Beginner',
        streak: 0,
        maxStreak: 0,
        badge: '🏅 Beginner',
        points: 0,
        loginStreak: 1,
        weight: 70,
        height: 1.70,
        bmi: '24.2 (Normal)',
        totalCalories: 0,
        co2Saved: 0,
        unlockedExercises: ['Push-ups', 'Squats', 'Running']
    };
    
    users.push(newUser);
    currentUser = newUser;
    safeUpdateTextContent('logged-in-username', username);
    
    // Clear register form
    usernameInput.value = '';
    passwordInput.value = '';
    if (backgroundInput) backgroundInput.value = '';
    
    // Update leaderboard to include new user
    populateLeaderboard();
    showScreen('mainApp');
    console.log("Registration successful:", username);
}

// Save profile changes
function saveProfileChanges() {
    console.log("Saving profile changes");
    if (!currentUser) {
        alert('No user logged in!');
        return;
    }
    
    const usernameInput = document.getElementById('update-username');
    const weightInput = document.getElementById('update-weight');
    const heightInput = document.getElementById('update-height');
    const backgroundInput = document.getElementById('update-background');
    
    if (!usernameInput || !weightInput || !heightInput || !backgroundInput) {
        alert('Update profile form elements not found!');
        return;
    }
    
    const newUsername = usernameInput.value;
    const newWeight = parseFloat(weightInput.value);
    const newHeight = parseFloat(heightInput.value);
    const newBackground = backgroundInput.value;
    
    // Validate input
    if (!newUsername || isNaN(newWeight) || isNaN(newHeight)) {
        alert('Please fill in all required fields with valid values!');
        return;
    }
    
    // Check if new username is already taken (except by current user)
    if (newUsername.toLowerCase() !== currentUser.username.toLowerCase() && 
        users.some(u => u.username.toLowerCase() === newUsername.toLowerCase())) {
        alert('Username already exists!');
        return;
    }
    
    // Update user data
    currentUser.username = newUsername;
    currentUser.weight = newWeight;
    currentUser.height = newHeight;
    currentUser.background = newBackground;
    
    // Recalculate BMI
    const bmiValue = newWeight / (newHeight * newHeight);
    let bmiCategory = 'Underweight';
    if (bmiValue >= 18.5 && bmiValue < 25) {
        bmiCategory = 'Normal';
    } else if (bmiValue >= 25 && bmiValue < 30) {
        bmiCategory = 'Overweight';
    } else if (bmiValue >= 30) {
        bmiCategory = 'Obese';
    }
    currentUser.bmi = `${bmiValue.toFixed(1)} (${bmiCategory})`;
    
    // Update profile view
    updateProfileView();
    
    // Update leaderboard
    populateLeaderboard();
    
    alert('Profile updated successfully!');
    showScreen('profileView');
    console.log("Profile updated for:", currentUser.username);
}

// Reset password handler
function handleResetPassword() {
    console.log("Reset password attempt");
    const usernameInput = document.getElementById('reset-username');
    const newPasswordInput = document.getElementById('reset-new-password');
    
    if (!usernameInput || !newPasswordInput) {
        alert('Reset password form elements not found!');
        return;
    }
    
    const username = usernameInput.value.toLowerCase();
    const newPassword = newPasswordInput.value;
    
    if (!username || !newPassword) {
        alert('Please fill in all fields!');
        return;
    }
    
    const userIndex = users.findIndex(u => u.username.toLowerCase() === username);
    
    if (userIndex !== -1) {
        users[userIndex].password = newPassword;
        alert('Password reset successfully!');
        showScreen('welcomeScreen');
        
        // Clear reset form
        usernameInput.value = '';
        newPasswordInput.value = '';
        console.log("Password reset successful for:", username);
    } else {
        alert('Username not found!');
        console.log("Password reset failed - username not found:", username);
    }
}

// Logout handler
function handleLogout() {
    console.log("User logged out");
    currentUser = null;
    showScreen('welcomeScreen');
}

// Setup exercise detail view
function setupExerciseDetail(exercise) {
    console.log("Setting up exercise detail for:", exercise.name);
    
    // Update exercise detail screen with exercise info - safely
    const headerElement = document.querySelector('#exercise-detail .box-header h2');
    if (headerElement) {
        headerElement.textContent = exercise.name;
    }
    
    const exerciseContainer = document.querySelector('#exercise-detail .exercise');
    if (!exerciseContainer) {
        console.warn("Exercise container not found!");
        return;
    }
    
    const infoDiv = exerciseContainer.querySelector('div:nth-child(2)');
    if (!infoDiv) {
        console.warn("Info div not found in exercise container!");
        return;
    }
    
    const categoryP = infoDiv.querySelector('p');
    if (categoryP) {
        categoryP.textContent = exercise.category;
    }
    
    const infoRows = infoDiv.querySelectorAll('div > div');
    if (infoRows && infoRows.length >= 2) {
        const caloriesSpan = infoRows[0].querySelector('span:first-child');
        const co2Span = infoRows[1].querySelector('span:first-child');
        
        if (caloriesSpan) {
            caloriesSpan.textContent = `🔥 Calories: ${exercise.caloriesPerMin} kcal/min`;
        }
        
        if (co2Span) {
            co2Span.textContent = `🌱 CO₂ Saved: ${exercise.co2SavedPerMin} g/min`;
        }
    }
    
    const muscleGroupH3 = infoDiv.querySelector('h3');
    if (muscleGroupH3) {
        muscleGroupH3.textContent = `Muscle Group: ${exercise.muscleGroup}`;
    }
    
    const stepsList = infoDiv.querySelector('.exercise-steps ol');
    if (stepsList) {
        stepsList.innerHTML = '';
        exercise.steps.forEach(step => {
            const li = document.createElement('li');
            li.textContent = step;
            stepsList.appendChild(li);
        });
    }
}

// Workout timer variables
let workoutTimer;
let secondsElapsed = 0;
let currentExercise = null;

// Start exercise session
function startExerciseSession() {
    console.log("Starting exercise session");
    
    const headerElement = document.querySelector('#exercise-detail .box-header h2');
    if (!headerElement) {
        alert('Exercise detail not found!');
        return;
    }
    
    const exerciseName = headerElement.textContent;
    const intensitySelect = document.getElementById('exercise-intensity');
    
    if (!intensitySelect) {
        alert('Intensity selector not found!');
        return;
    }
    
    const intensity = intensitySelect.value;
    
    currentExercise = exercises.find(ex => ex.name === exerciseName);
    
    if (currentExercise) {
        // Update active workout screen safely
        const nameElement = document.querySelector('#active-workout .workout-session h3');
        const intensityElement = document.querySelector('#active-workout .workout-session p:nth-of-type(1)');
        const timeElement = document.querySelector('#active-workout .workout-session p:nth-of-type(2)');
        
        if (nameElement) {
            nameElement.textContent = currentExercise.name;
        }
        
        if (intensityElement) {
            intensityElement.textContent = `Intensity: ${intensity}/10`;
        }
        
        if (timeElement) {
            const now = new Date();
            const timeString = now.toLocaleTimeString();
            timeElement.textContent = `Start Time: ${timeString}`;
        }
        
        // Set up steps
        const stepsList = document.querySelector('#active-workout .workout-session ol');
        if (stepsList) {
            stepsList.innerHTML = '';
            currentExercise.steps.forEach(step => {
                const li = document.createElement('li');
                li.textContent = step;
                stepsList.appendChild(li);
            });
        }
        
        // Reset and start timer
        secondsElapsed = 0;
        const timerElement = document.querySelector('#active-workout .workout-timer');
        const progressBarElement = document.querySelector('#active-workout .progress-bar');
        
        if (timerElement) {
            timerElement.textContent = formatTime(secondsElapsed);
        }
        
        if (progressBarElement) {
            progressBarElement.style.width = '0%';
            progressBarElement.textContent = '0% Complete';
        }
        
        workoutTimer = setInterval(() => {
            secondsElapsed++;
            
            if (timerElement) {
                timerElement.textContent = formatTime(secondsElapsed);
                // Update progress (assuming 15-minute workout is 100%)
            const progress = Math.min(100, Math.round((secondsElapsed / 900) * 100));
            
            if (progressBarElement) {
                progressBarElement.style.width = `${progress}%`;
                progressBarElement.textContent = `${progress}% Complete`;
            }
                } else {
            clearInterval(workoutTimer);
        }
    }, 1000);
        
        showScreen('activeWorkout');
        console.log("Exercise session started:", currentExercise.name);
    } else {
        alert('Exercise not found!');
    }
}

// End workout session
function endWorkoutSession() {
    console.log("Ending workout session");
    
    // Stop timer
    clearInterval(workoutTimer);
    
    if (!currentUser || !currentExercise) {
        alert('No active session or user!');
        return;
    }
    
    // Calculate results
    const duration = secondsElapsed / 60; // Convert to minutes
    const caloriesBurned = Math.round(duration * currentExercise.caloriesPerMin);
    const co2Saved = Math.round(duration * currentExercise.co2SavedPerMin);
    const pointsEarned = Math.round(duration * currentExercise.pointsReward / 10);
    
    // Update user stats
    currentUser.totalCalories += caloriesBurned;
    currentUser.co2Saved += co2Saved;
    currentUser.points += pointsEarned;
    currentUser.streak += 1;
    if (currentUser.streak > currentUser.maxStreak) {
        currentUser.maxStreak = currentUser.streak;
    }
    
    // Update badge based on new points
    updateUserBadge();
    
    // Add to workout history
    const today = new Date();
    const dateString = today.toISOString().split('T')[0];
    workoutHistory.unshift({
        date: dateString,
        exercise: currentExercise.name,
        duration: `${Math.round(duration)} min`,
        calories: `${caloriesBurned} kcal`,
        points: pointsEarned
    });
    
    // Update end workout screen safely
    const exerciseNameElement = document.querySelector('#end-workout .workout-summary h3');
    if (exerciseNameElement) {
        exerciseNameElement.textContent = currentExercise.name;
    }
    
    const durationElement = document.querySelector('#end-workout .workout-summary p:nth-of-type(1)');
    if (durationElement) {
        durationElement.textContent = `Duration: ${Math.round(duration)} minutes`;
    }
    
    const caloriesElement = document.querySelector('#end-workout .workout-summary p:nth-of-type(2)');
    if (caloriesElement) {
        caloriesElement.textContent = `Calories Burned: ${caloriesBurned} kcal`;
    }
    
    const co2Element = document.querySelector('#end-workout .workout-summary p:nth-of-type(3)');
    if (co2Element) {
        co2Element.textContent = `CO₂ Saved: ${co2Saved} g`;
    }
    
    const pointsElement = document.querySelector('#end-workout .workout-summary p:nth-of-type(4)');
    if (pointsElement) {
        pointsElement.textContent = `Points Earned: ${pointsEarned}`;
    }
    
    // Check if this workout set a new personal best
    const existingBest = personalBests.find(pb => pb.exercise === currentExercise.name);
    let newBest = false;
    
    if (existingBest) {
        // Example comparison for duration-based workouts
        const existingDuration = parseInt(existingBest.record);
        if (duration > existingDuration) {
            existingBest.record = `${Math.round(duration)} min`;
            existingBest.date = dateString;
            newBest = true;
        }
    } else {
        // Add as new personal best
        personalBests.push({
            exercise: currentExercise.name,
            record: `${Math.round(duration)} min`,
            date: dateString
        });
        newBest = true;
    }
    
    if (newBest) {
        const newBestElement = document.querySelector('#end-workout .workout-summary .new-best');
        if (newBestElement) {
            newBestElement.classList.remove('hidden');
        }
    } else {
        const newBestElement = document.querySelector('#end-workout .workout-summary .new-best');
        if (newBestElement) {
            newBestElement.classList.add('hidden');
        }
    }
    
    // Reset current exercise
    currentExercise = null;
    
    // Update workout history
    populateWorkoutHistory();
    
    // Update personal bests
    populatePersonalBests();
    
    showScreen('endWorkout');
    console.log("Workout session ended");
}

// Generate workout plan
function generateWorkoutPlan() {
    console.log("Generating workout plan");
    
    const levelSelect = document.getElementById('plan-level');
    const durationSelect = document.getElementById('plan-duration');
    const goalSelect = document.getElementById('plan-goal');
    
    if (!levelSelect || !durationSelect || !goalSelect) {
        alert('Form elements not found!');
        return;
    }
    
    const level = levelSelect.value;
    const duration = durationSelect.value;
    const goal = goalSelect.value;
    
    // Generate plan based on selections
    let planExercises = [];
    
    // Add exercises based on level and goal
    if (goal === 'strength') {
        planExercises.push({
            name: 'Push-ups',
            sets: level === 'beginner' ? 2 : (level === 'intermediate' ? 3 : 4),
            reps: level === 'beginner' ? 8 : (level === 'intermediate' ? 12 : 15)
        });
        planExercises.push({
            name: 'Squats',
            sets: level === 'beginner' ? 2 : (level === 'intermediate' ? 3 : 4),
            reps: level === 'beginner' ? 10 : (level === 'intermediate' ? 15 : 20)
        });
    } else if (goal === 'cardio') {
        planExercises.push({
            name: 'Running',
            duration: level === 'beginner' ? 10 : (level === 'intermediate' ? 15 : 20),
            intensity: level === 'beginner' ? 'Light' : (level === 'intermediate' ? 'Moderate' : 'High')
        });
        planExercises.push({
            name: 'Jumping Jacks',
            sets: level === 'beginner' ? 2 : (level === 'intermediate' ? 3 : 4),
            reps: level === 'beginner' ? 20 : (level === 'intermediate' ? 30 : 40)
        });
    } else {
        // Mixed goal
        planExercises.push({
            name: 'Push-ups',
            sets: level === 'beginner' ? 2 : (level === 'intermediate' ? 3 : 3),
            reps: level === 'beginner' ? 8 : (level === 'intermediate' ? 10 : 12)
        });
        planExercises.push({
            name: 'Running',
            duration: level === 'beginner' ? 8 : (level === 'intermediate' ? 12 : 15),
            intensity: level === 'beginner' ? 'Light' : (level === 'intermediate' ? 'Moderate' : 'High')
        });
    }
    
    // Adjust for duration
    if (duration === '30min') {
        planExercises.forEach(ex => {
            if (ex.sets) ex.sets = Math.round(ex.sets * 1.5);
            if (ex.duration) ex.duration = Math.round(ex.duration * 1.5);
        });
    } else if (duration === '45min') {
        planExercises.forEach(ex => {
            if (ex.sets) ex.sets = Math.round(ex.sets * 2);
            if (ex.duration) ex.duration = Math.round(ex.duration * 2);
        });
    }
    
    // Update generated plan screen
    const planLevelElement = document.querySelector('#generated-plan .plan-summary p:nth-of-type(1)');
    if (planLevelElement) {
        planLevelElement.textContent = `Level: ${level.charAt(0).toUpperCase() + level.slice(1)}`;
    }
    
    const planDurationElement = document.querySelector('#generated-plan .plan-summary p:nth-of-type(2)');
    if (planDurationElement) {
        planDurationElement.textContent = `Duration: ${duration}`;
    }
    
    const planGoalElement = document.querySelector('#generated-plan .plan-summary p:nth-of-type(3)');
    if (planGoalElement) {
        planGoalElement.textContent = `Goal: ${goal.charAt(0).toUpperCase() + goal.slice(1)}`;
    }
    
    // Update exercises list
    const exercisesList = document.querySelector('#generated-plan .exercises-list');
    if (exercisesList) {
        exercisesList.innerHTML = '';
        
        planExercises.forEach(ex => {
            const li = document.createElement('li');
            if (ex.sets && ex.reps) {
                li.textContent = `${ex.name}: ${ex.sets} sets x ${ex.reps} reps`;
            } else if (ex.duration) {
                li.textContent = `${ex.name}: ${ex.duration} minutes (${ex.intensity} intensity)`;
            }
            exercisesList.appendChild(li);
        });
    }
    
    showScreen('generatedPlan');
    console.log("Workout plan generated:", {level, duration, goal});
}

// Start plan session
function startPlanSession() {
    // Similar to startExerciseSession but for the entire plan
    // For simplicity, we'll just redirect to the start workout screen
    showScreen('startWorkout');
    alert('Plan started! Please select exercises to begin.');
}

// Change password
function changePassword() {
    console.log("Changing password");
    
    if (!currentUser) {
        alert('No user logged in!');
        return;
    }
    
    const currentPasswordInput = document.getElementById('current-password');
    const newPasswordInput = document.getElementById('new-password');
    const confirmPasswordInput = document.getElementById('confirm-password');
    
    if (!currentPasswordInput || !newPasswordInput || !confirmPasswordInput) {
        alert('Password form elements not found!');
        return;
    }
    
    const currentPassword = currentPasswordInput.value;
    const newPassword = newPasswordInput.value;
    const confirmPassword = confirmPasswordInput.value;
    
    if (!currentPassword || !newPassword || !confirmPassword) {
        alert('Please fill in all fields!');
        return;
    }
    
    if (currentPassword !== currentUser.password) {
        alert('Current password is incorrect!');
        return;
    }
    
    if (newPassword !== confirmPassword) {
        alert('New passwords do not match!');
        return;
    }
    
    // Update password
    currentUser.password = newPassword;
    
    // Clear form
    currentPasswordInput.value = '';
    newPasswordInput.value = '';
    confirmPasswordInput.value = '';
    
    alert('Password changed successfully!');
    showScreen('mainApp');
    console.log("Password changed for:", currentUser.username);
}

// Save new goal
function saveGoal() {
    console.log("Saving new goal");
    
    if (!currentUser) {
        alert('No user logged in!');
        return;
    }
    
    const goalTitleInput = document.getElementById('goal-title');
    const goalTargetInput = document.getElementById('goal-target');
    const goalDateInput = document.getElementById('goal-date');
    
    if (!goalTitleInput || !goalTargetInput || !goalDateInput) {
        alert('Goal form elements not found!');
        return;
    }
    
    const title = goalTitleInput.value;
    const target = goalTargetInput.value;
    const date = goalDateInput.value;
    
    if (!title || !target || !date) {
        alert('Please fill in all fields!');
        return;
    }
    
    // Add new goal
    goals.push({
        title: title,
        current: '0/' + target,
        progress: 0,
        due: date
    });
    
    // Clear form
    goalTitleInput.value = '';
    goalTargetInput.value = '';
    goalDateInput.value = '';
    
    // Update current goals
    populateCurrentGoals();
    
    alert('Goal added successfully!');
    showScreen('currentGoals');
    console.log("New goal added:", title);
}

// Populate leaderboard
function populateLeaderboard() {
    console.log("Populating leaderboard");
    
    const leaderboardBody = document.querySelector('#leaderboard table tbody');
    if (!leaderboardBody) {
        console.warn("Leaderboard table body not found!");
        return;
    }
    
    // Sort users by points (descending)
    const sortedUsers = [...users].sort((a, b) => b.points - a.points);
    
    // Clear and populate table
    leaderboardBody.innerHTML = '';
    
    sortedUsers.forEach((user, index) => {
        const row = document.createElement('tr');
        
        const rankCell = document.createElement('td');
        rankCell.textContent = index + 1;
        row.appendChild(rankCell);
        
        const usernameCell = document.createElement('td');
        usernameCell.textContent = user.username;
        row.appendChild(usernameCell);
        
        const badgeCell = document.createElement('td');
        badgeCell.textContent = user.badge;
        row.appendChild(badgeCell);
        
        const pointsCell = document.createElement('td');
        pointsCell.textContent = user.points;
        row.appendChild(pointsCell);
        
        const streakCell = document.createElement('td');
        streakCell.textContent = user.streak;
        row.appendChild(streakCell);
        
        // Highlight current user
        if (currentUser && user.username === currentUser.username) {
            row.classList.add('current-user');
        }
        
        leaderboardBody.appendChild(row);
    });
}

// Populate workout history
function populateWorkoutHistory() {
    console.log("Populating workout history");
    
    const historyBody = document.querySelector('#workout-history table tbody');
    if (!historyBody) {
        console.warn("Workout history table body not found!");
        return;
    }
    
    // Clear and populate table
    historyBody.innerHTML = '';
    
    workoutHistory.forEach(workout => {
        const row = document.createElement('tr');
        
        const dateCell = document.createElement('td');
        dateCell.textContent = workout.date;
        row.appendChild(dateCell);
        
        const exerciseCell = document.createElement('td');
        exerciseCell.textContent = workout.exercise;
        row.appendChild(exerciseCell);
        
        const durationCell = document.createElement('td');
        durationCell.textContent = workout.duration;
        row.appendChild(durationCell);
        
        const caloriesCell = document.createElement('td');
        caloriesCell.textContent = workout.calories;
        row.appendChild(caloriesCell);
        
        const pointsCell = document.createElement('td');
        pointsCell.textContent = workout.points;
        row.appendChild(pointsCell);
        
        historyBody.appendChild(row);
    });
}

// Populate current goals
function populateCurrentGoals() {
    console.log("Populating current goals");
    
    const goalsContainer = document.querySelector('#current-goals .goals-container');
    if (!goalsContainer) {
        console.warn("Goals container not found!");
        return;
    }
    
    // Clear and populate goals
    goalsContainer.innerHTML = '';
    
    goals.forEach(goal => {
        const goalElement = document.createElement('div');
        goalElement.className = 'goal-item';
        
        const titleElement = document.createElement('h3');
        titleElement.textContent = goal.title;
        goalElement.appendChild(titleElement);
        
        const currentElement = document.createElement('p');
        currentElement.textContent = `Current: ${goal.current}`;
        goalElement.appendChild(currentElement);
        
        const dueElement = document.createElement('p');
        dueElement.textContent = `Due: ${goal.due}`;
        goalElement.appendChild(dueElement);
        
        const progressContainer = document.createElement('div');
        progressContainer.className = 'progress-container';
        
        const progressBar = document.createElement('div');
        progressBar.className = 'progress-bar';
        progressBar.style.width = `${goal.progress}%`;
        progressBar.textContent = `${goal.progress}%`;
        
        progressContainer.appendChild(progressBar);
        goalElement.appendChild(progressContainer);
        
        goalsContainer.appendChild(goalElement);
    });
}

// Populate personal bests
function populatePersonalBests() {
    console.log("Populating personal bests");
    
    const bestsBody = document.querySelector('#personal-bests table tbody');
    if (!bestsBody) {
        console.warn("Personal bests table body not found!");
        return;
    }
    
    // Clear and populate table
    bestsBody.innerHTML = '';
    
    personalBests.forEach(best => {
        const row = document.createElement('tr');
        
        const exerciseCell = document.createElement('td');
        exerciseCell.textContent = best.exercise;
        row.appendChild(exerciseCell);
        
        const recordCell = document.createElement('td');
        recordCell.textContent = best.record;
        row.appendChild(recordCell);
        
        const dateCell = document.createElement('td');
        dateCell.textContent = best.date;
        row.appendChild(dateCell);
        
        bestsBody.appendChild(row);
    });
}

// Initialize app on DOM content loaded
document.addEventListener('DOMContentLoaded', function() {
    console.log("DOM content loaded, initializing app...");
    
    // Initialize screen elements
    initScreens();
    
    // Initialize event listeners
    initEventListeners();
    
    // Populate data
    populateLeaderboard();
    populateWorkoutHistory();
    populateCurrentGoals();
    populatePersonalBests();
    
    // Show welcome screen
    showScreen('welcomeScreen');
    
    console.log("App initialization complete");
});