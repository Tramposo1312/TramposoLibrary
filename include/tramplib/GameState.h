#ifndef TRAMPLIB_GAME_STATE_H
#define TRAMPLIB_GAME_STATE_H

namespace tramplib {

    class Game;

    /**
     * @class GameState
     * @brief Base class for all game states.
     *
     * This class defines the interface for game states. Each state (e.g., MenuState, PlayState)
     * should inherit from this class and implement its methods.
     */
    class GameState {
    public:
        /**
         * @brief Constructor for GameState.
         * @param game Pointer to the Game object.
         */
        GameState(Game* game) : m_game(game) {}

        /**
         * @brief Virtual destructor for GameState.
         */
        virtual ~GameState() = default;

        /**
         * @brief Called when entering the state.
         */
        virtual void enter() = 0;

        /**
         * @brief Called when exiting the state.
         */
        virtual void exit() = 0;

        /**
         * @brief Updates the state.
         * @param deltaTime The time elapsed since the last update.
         */
        virtual void update(float deltaTime) = 0;

        /**
         * @brief Renders the state.
         */
        virtual void render() = 0;

    protected:
        Game* m_game; ///< Pointer to the Game object.
    };

} // namespace tramplib

#endif // TRAMPLIB_GAME_STATE_H