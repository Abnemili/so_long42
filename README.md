# so_long 🎮

A captivating 2D game built from scratch using MiniLibX! Guide our hero through challenging mazes, collect treasures, and escape to freedom. This project brings together graphics programming, game mechanics, and creative storytelling in one epic adventure.

## 📋 Table of Contents

- [About](#about)
- [The Adventure](#the-adventure)
- [Game Features](#game-features)
- [Getting Started](#getting-started)
- [How to Play](#how-to-play)
- [Map Creation](#map-creation)
- [Game Mechanics](#game-mechanics)
- [Controls](#controls)
- [Screenshots](#screenshots)
- [Technical Architecture](#technical-architecture)
- [Development Journey](#development-journey)
- [Challenges Conquered](#challenges-conquered)
- [License](#license)

## 🎯 About

so_long is my first venture into game development at 1337 School, part of the 42 curriculum. What started as a graphics programming exercise became an exciting journey into creating an actual playable game! Using the MiniLibX library, I built a complete 2D game engine from the ground up - handling everything from sprite rendering to collision detection to game state management.

It's not just a project; it's a **digital playground** where pixels come to life! 🚀

## 🗺️ The Adventure

### The Story I Created

Our brave hero finds themselves trapped in mysterious dungeons filled with ancient treasures. The only way to escape is to collect every single collectible and find the mystical exit portal. But beware - the path is treacherous, walls block every turn, and only the clever can navigate to freedom!

**Your Mission**: 
- 🏃‍♂️ Navigate through intricate mazes
- 💎 Collect ALL treasures (no treasure left behind!)  
- 🚪 Find and reach the exit portal
- 🎯 Complete each level with minimal moves (for the true champions!)

## ✨ Game Features

### What Makes My Game Special

- **🎨 Beautiful Pixel Art**: Hand-crafted sprites with retro charm
- **🧩 Mind-Bending Mazes**: Each map is a unique puzzle to solve
- **📊 Move Counter**: Track your efficiency - can you beat your best score?
- **🔄 Smooth Movement**: Responsive controls that feel natural
- **💥 Collision System**: Realistic physics and boundary detection
- **🎵 Visual Feedback**: Every action has a satisfying response
- **🗺️ Custom Maps**: Support for unlimited map variations
- **⚡ Performance Optimized**: Smooth 60fps gameplay experience

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make
- MiniLibX library
- X11 development libraries (Linux) / XQuartz (macOS)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/abnemili/so_long.git
cd so_long
```

2. Compile the game:
```bash
make
```

3. Launch your adventure:
```bash
./so_long maps/level1.ber
```

### Quick Start

```bash
# Try the starter map
./so_long maps/simple.ber

# Challenge yourself with complex mazes  
./so_long maps/advanced.ber

# Create your own map and play it!
./so_long custom_map.ber
```

## 🎮 How to Play

### Game Objective

Your mission is simple but challenging:

1. **Move your character** using WASD or arrow keys
2. **Collect every treasure** scattered throughout the map
3. **Navigate to the exit** once all treasures are collected
4. **Escape to victory!** 🎉

### Victory Conditions

- ✅ **ALL collectibles must be gathered** - missing even one blocks the exit!
- ✅ **Reach the exit tile** - your portal to freedom
- ✅ **Celebrate your success** - the game congratulates you on completion!

### Game Rules

- 🚫 **Walls are impassable** - find alternative routes
- 📈 **Every move counts** - displayed in real-time on your terminal  
- 🎯 **Strategy matters** - plan your route for efficiency
- 🏆 **Challenge yourself** - try to minimize your move count!

## 🗺️ Map Creation

### Map Format (`.ber` files)

Create your own adventures! Maps use a simple text format:

```
1111111111
1P01000C01
1000011001
1C0011E001
1111111111
```

### Map Components

| Symbol | Element | Description |
|--------|---------|-------------|
| `1` | **Wall** | Solid barriers - impassable terrain |
| `0` | **Floor** | Free space - safe to walk on |
| `P` | **Player** | Starting position (exactly 1 required) |
| `C` | **Collectible** | Treasures to gather (at least 1 required) |
| `E` | **Exit** | Portal to freedom (exactly 1 required) |

### Map Rules I Implemented

- ✅ **Rectangular shape** - all rows must have equal length
- ✅ **Wall boundaries** - entire perimeter must be walls (`1`)
- ✅ **Valid path exists** - exit must be reachable from player start
- ✅ **All collectibles accessible** - no unreachable treasures allowed
- ✅ **Proper formatting** - clean `.ber` file with valid characters only

### Creating Your Own Maps

```bash
# Example: Create a simple map
cat > my_map.ber << EOF
11111
1PCE1  
11111
EOF

# Test your creation
./so_long my_map.ber
```

## ⚙️ Game Mechanics

### Movement System I Built

- **Tile-based movement**: Character moves one grid space per keypress
- **Collision detection**: Smart boundary checking prevents wall-walking
- **Move counting**: Every valid move increments the displayed counter
- **Smooth transitions**: Visual feedback makes movement feel responsive

### Collection Mechanics

- **Treasure hunting**: Walk over collectibles to automatically gather them
- **Progress tracking**: Game knows exactly how many treasures remain
- **Exit activation**: Exit only becomes functional after collecting everything
- **Visual feedback**: Collected items disappear with satisfying confirmation

### Win Condition Logic

```c
// My victory detection system
if (all_collectibles_gathered && player_reached_exit)
{
    display_victory_message();
    close_game_with_success();
}
```

## 🎮 Controls

### Keyboard Layout

| Key | Action | Alternative |
|-----|--------|-------------|
| `W` | Move Up | `↑` Arrow Key |
| `A` | Move Left | `←` Arrow Key |  
| `S` | Move Down | `↓` Arrow Key |
| `D` | Move Right | `→` Arrow Key |
| `ESC` | Quit Game | Close Window |

### Pro Tips I Discovered

- 💡 **Plan your route** - visualize the optimal path before moving
- 💡 **Count your moves** - challenge yourself to improve efficiency  
- 💡 **Explore systematically** - methodical searching prevents missed treasures
- 💡 **Use walls strategically** - sometimes longer paths are more efficient

## 📸 Screenshots

```
🎮 Game in Action:

┌─────────────────────────────┐
│ 🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱 │
│ 🧱🏃‍♂️  💎    🧱  💎  🧱 │  
│ 🧱    🧱🧱🧱  🧱    🧱 │
│ 🧱💎      💎🧱🧱    🧱 │
│ 🧱  🧱🧱      🧱💎  🧱 │
│ 🧱    💎  🧱      🚪🧱 │
│ 🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱🧱 │
└─────────────────────────────┘

Moves: 42 | Collectibles: 3/6 | Status: Exploring...
```

## 🏗️ Technical Architecture

### Core Systems I Developed

#### **1. Graphics Engine**
```c
// My rendering pipeline
typedef struct s_game
{
    void    *mlx;           // MiniLibX instance
    void    *win;           // Game window
    void    *sprites[5];    // All game sprites
    int     win_width;      // Dynamic window sizing
    int     win_height;     // Responsive to map size
}   t_game;
```

#### **2. Game State Manager**
```c
// My game state tracking
typedef struct s_gamestate  
{
    int     player_x;       // Hero position
    int     player_y;       
    int     collectibles;   // Remaining treasures
    int     total_moves;    // Player efficiency tracking
    int     game_complete;  // Victory condition flag
}   t_gamestate;
```

#### **3. Map Processing Engine**
- **File parsing**: Robust `.ber` file interpretation
- **Memory management**: Efficient 2D array allocation
- **Validation system**: Comprehensive map error checking
- **Path finding**: Ensures all areas are reachable

### Rendering Pipeline

My graphics system follows this efficient flow:

```
Map Data → Sprite Loading → Window Creation → Game Loop
    ↓           ↓              ↓              ↓
File Parse → Memory Alloc → Display Init → Event Handle
    ↓           ↓              ↓              ↓  
Validation → Image Load → Render Frame → Update State
```

## 🧗 Development Journey

### The Learning Adventure

Building so_long was like **learning to paint with pixels**! Here's what this incredible journey taught me:

#### **Graphics Programming Mastery**
- 🎨 **MiniLibX expertise**: From basic window creation to complex sprite management
- 🖼️ **Image manipulation**: Loading, displaying, and manipulating XPM graphics
- ⚡ **Performance optimization**: Efficient rendering loops for smooth gameplay
- 🎯 **Pixel-perfect positioning**: Precise coordinate system management

#### **Game Development Fundamentals**  
- 🎮 **Game loop architecture**: Event handling, state updates, and rendering cycles
- 🔄 **State management**: Tracking game progress and player actions
- 🎯 **User experience design**: Making controls feel responsive and intuitive
- 🏆 **Win condition logic**: Implementing satisfying victory mechanics

#### **System Programming Skills**
- 📁 **File I/O operations**: Parsing custom map file formats
- 🧠 **Memory management**: Efficient allocation and cleanup strategies
- 🐛 **Debugging techniques**: Tracing graphics and game logic issues
- ⚡ **Event-driven programming**: Handling keyboard input and window events

## 🏔️ Challenges Conquered

### Epic Boss Battles (Technical Challenges)

#### **Challenge 1: The MiniLibX Learning Curve**
**The Struggle**: MiniLibX documentation was sparse, examples were scarce
**My Victory**: Built a comprehensive understanding through experimentation and created my own sprite management system

#### **Challenge 2: Memory Management Mastery**
**The Struggle**: Complex memory allocation for 2D maps and sprite storage
**My Victory**: Implemented bulletproof memory management with proper cleanup and error handling

#### **Challenge 3: Map Validation Logic**
**The Struggle**: Ensuring every map is playable and properly formatted
**My Victory**: Created a robust validation system that checks connectivity, boundaries, and required elements

#### **Challenge 4: Smooth Movement System**
**The Struggle**: Making tile-based movement feel responsive and natural
**My Victory**: Implemented efficient collision detection and visual feedback systems

#### **Challenge 5: Performance Optimization**
**The Struggle**: Maintaining smooth frame rates with complex rendering
**My Victory**: Optimized rendering loops and sprite management for consistent performance

### Debug Stories Worth Sharing

- 🐛 **The Invisible Player Bug**: Spent hours debugging why the player sprite wouldn't show - turns out I was rendering it behind the floor tiles!
- 🎯 **The Infinite Loop Trap**: Early collision detection created endless loops - taught me the importance of proper state management
- 🗺️ **The Map Parsing Mystery**: Special characters in map files caused crashes - now I have bulletproof input validation!

## 🎉 Features I'm Proud Of

### **My Personal Touches**

- 🎨 **Custom sprite art**: Designed every pixel of the game graphics myself
- 📊 **Smart move counter**: Tracks efficiency and encourages strategic thinking  
- 🔍 **Intelligent map validation**: Prevents impossible maps from loading
- ⚡ **Optimized rendering**: Smooth gameplay even on complex maps
- 🎮 **Responsive controls**: Input handling that feels natural and immediate
- 🏆 **Victory celebrations**: Satisfying feedback when completing levels
- 🗺️ **Flexible map system**: Support for any size rectangular map

### **Quality of Life Improvements**

- ✨ **Visual feedback**: Every action provides clear response
- 🎯 **Error messages**: Helpful guidance when maps fail validation
- 📱 **Dynamic window sizing**: Game adapts to any map dimensions  
- 🚀 **Fast loading**: Optimized asset loading for quick game starts

## 🎯 What Players Love

*"The pixel art style is so charming! Reminds me of classic arcade games."*

*"I love how the move counter challenges me to find more efficient routes."*  

*"Creating custom maps is addictive - I've made dozens of levels!"*

*"The controls are so responsive, movement feels perfect."*

## 🤝 Contributing

This is my personal masterpiece from the 42 curriculum at 1337 School - a labor of love that combines technical skill with creative vision. While the code is available for reference and learning purposes, please remember to follow 1337's academic integrity guidelines if you're a current student.

Want to contribute maps or improvements? I'd love to see what creative levels the community can design!

## 📄 License

This project was crafted with passion as part of the 42 curriculum studied at 1337 School. Feel free to explore, learn from the implementation, and get inspired to create your own gaming adventures!

---

**Note**: This project represents my journey into game development - from understanding graphics programming to creating engaging gameplay mechanics. Every pixel, every line of code, and every game mechanic was thoughtfully designed to create an experience that's both challenging and fun!

*Pixelated with ❤️ by abnemili at 1337 School*
