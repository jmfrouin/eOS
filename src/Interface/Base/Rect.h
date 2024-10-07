#ifndef RECT_H
#define RECT_H

namespace Interface
{
  /**
   * @class CRect
   * @brief A class representing a rectangle with various utility functions.
   */
  class CRect {
    private:
    int fLeft;
    int fTop;
    int fRight;
    int fBottom;
    int fWidth;
    int fHeight;

    public:
    CRect();
    CRect(bool invalidate);
    CRect(const CRect& source);
    CRect(int w, int h);
    CRect(int x, int y, int w, int h);

    int Left() const;
    int Top() const;
    int Right() const;
    int Bottom() const;
    int Width() const;
    int Height() const;
    int HCenter() const;
    int VCenter() const;

    void Left(int v);
    void Top(int v);
    void Right(int v);
    void Bottom(int v);
    void Width(int v);
    void Height(int v);

    void Invalidate();
    bool Valid() const;
    bool Null() const;

    bool operator == (const CRect& rect) const;
    bool operator != (const CRect& rect) const;

    void MoveLeft(int dl);
    void MoveRight(int dr);
    void MoveTop(int dt);
    void MoveBottom(int db);

    void Set(const CRect& source);
    void Set(int x, int y, int w, int h);

    void Move(int dx, int dy);
    void MoveTo(int x, int y);

    bool CheckSize(const CRect& source);
    bool CheckPosition(const CRect& source);

    void Resize(int w, int h);
    void Grow(const CRect& rect);
    void Intersect(const CRect& rect);
    void MoveIn(const CRect &rect);
    bool Collide(const CRect& rect) const;
    void Center(const CRect ref, bool hz, bool vt);
    void Expand(int p);
    void Expand(int dx, int dy);
    void Contract(int p);
    void Contract(int dx, int dy);

    bool In(int x, int y) const;
  };
}
#endif //RECT_H