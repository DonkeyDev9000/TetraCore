#pragma once

#include <vector>

#pragma mark TetraInput --------------------------------------------------------------------------------------------------------------------
enum TetraInput {
    moveLeft,
    moveRight,
    moveDown,
    spinLeft,
    spinRight,
};

#pragma mark TetraInput --------------------------------------------------------------------------------------------------------------------
enum TetraType {
    TypeZee,
    TypeReverseZee,
    TypeBlock,
    TypeEl,
    TypeReverseEl,
    TypeTee,
    TypeLine,
};

#pragma mark TetraBlock --------------------------------------------------------------------------------------------------------------------
struct TetraBlock {
    int mX{};
    int mY{};
};

#pragma mark TetraWorldInterface -----------------------------------------------------------------------------------------------------------
class TetraWorldInterface {
public:
    static std::shared_ptr<TetraWorldInterface> create();

    virtual ~TetraWorldInterface() = default;

    [[nodiscard]] virtual bool isGameOver() const = 0;
    [[nodiscard]] virtual size_t getWidth() const = 0;
    [[nodiscard]] virtual size_t getHeight() const = 0;

    virtual void worldStep(const bool hardPush) = 0;
    virtual void inputReceived(const std::vector<TetraInput> &inputs) = 0;
    [[nodiscard]] virtual bool canExist(int x, int y) const = 0;
    [[nodiscard]] virtual std::vector<TetraBlock> getCurrentWorld() = 0;
};

#pragma mark TetraGroup --------------------------------------------------------------------------------------------------------------------
class TetraGroup {
public:
    virtual ~TetraGroup() = default;
    [[maybe_unused]] virtual bool tryInput(const TetraInput &input) = 0;
    [[nodiscard]] virtual std::vector<TetraBlock> getGroupCoordinates() const = 0;
};
