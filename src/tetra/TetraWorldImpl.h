#pragma once

#include "TetraBlocks.h"

#include <random>
#include <optional>

class TetraGenerator {
    mutable std::mt19937 gen;
    mutable std::uniform_int_distribution<> dis;

public:
    TetraGenerator();
    TetraType getRnd() const;
};

class TetraBoard : public TetraWorldInterface,
                   public std::enable_shared_from_this<TetraBoard> {
    static constexpr size_t sDefaultWidth = 10;
    static constexpr size_t sDefaultHeight = 19;

    const size_t mMaxX;
    const size_t mMaxY;
    bool mIsGameOver{false};
    bool mIsForcePush{false};

    std::vector<std::vector<std::optional<TetraBlock>>> mBoard;

    TetraGenerator mGenerator{};
    std::shared_ptr<TetraGroup> mCurrentTetraGroup{};

    void addCurrentGroupToBoard();
    std::shared_ptr<TetraGroup> generate();

public:
    explicit TetraBoard(size_t x = sDefaultWidth, size_t y = sDefaultHeight);
    ~TetraBoard() override = default;

    [[nodiscard]] bool isGameOver() const override;
    [[nodiscard]] size_t getWidth() const override;
    [[nodiscard]] size_t getHeight() const override;

    void initialize();
    bool canExist(int x, int y) const override;
    void worldStep(const bool hardPush) override;
    void inputReceived(const std::vector<TetraInput> &inputs) override;
    std::vector<TetraBlock> getCurrentWorld() override;
};
