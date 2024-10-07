//
// Created by Jean-Michel Frouin on 07/10/2024.
//
#include "Rect.h"

namespace Interface
{
  CRect::CRect() {
    Set(0,0,0,0);
  }

  CRect::CRect(bool invalidate) {
    if (invalidate) Invalidate();
    else Set(0,0,0,0);
  }

  CRect::CRect(const CRect& source) {
    Set(source);
  }

  CRect::CRect(int w, int h) {
    Set(0,0,w,h);
  }

  CRect::CRect(int x, int y, int w, int h) {
    Set(x,y,w,h);
  }

  int CRect::Left() const { return fLeft; }
  int CRect::Top() const { return fTop; }
  int CRect::Right() const { return fRight; }
  int CRect::Bottom() const { return fBottom; }
  int CRect::Width() const { return fWidth; }
  int CRect::Height() const { return fHeight; }
  int CRect::HCenter() const { return fLeft + (fWidth >> 1); }
  int CRect::VCenter() const { return fTop + (fHeight >> 1); }

  void CRect::Left(int v) { fLeft = v; fWidth = fRight-v+1; }
  void CRect::Top(int v) { fTop = v; fHeight = fBottom-v+1; }
  void CRect::Right(int v) { fRight = v; fWidth = fRight-v+1; }
  void CRect::Bottom(int v) { fBottom = v; fHeight = fBottom-v+1; }
  void CRect::Width(int v) { fWidth = v; fRight = fLeft+v-1; }
  void CRect::Height(int v) { fHeight = v; fBottom = fTop+v-1; }

  void CRect::Invalidate() { fLeft = fTop = fWidth = fHeight = -1; fRight = fBottom = -2; }
  bool CRect::Valid() const { return (((fWidth-1)|(fHeight-1))>=0); }
  bool CRect::Null() const { return ((fWidth|fHeight)==0); }

  bool CRect::operator == (const CRect& rect) const {
    return ((rect.fLeft-fLeft) | (rect.fRight-fRight) | (rect.fTop-fTop) | (rect.fBottom-fBottom)) == 0;
  }

  bool CRect::operator != (const CRect& rect) const {
    return ((rect.fLeft-fLeft) | (rect.fRight-fRight) | (rect.fTop-fTop) | (rect.fBottom-fBottom)) != 0;
  }

  void CRect::MoveLeft(int dl) {
    fLeft += dl;
    fWidth -= dl;
  }

  void CRect::MoveRight(int dr) {
    fRight += dr;
    fWidth += dr;
  }

  void CRect::MoveTop(int dt) {
    fTop += dt;
    fHeight -= dt;
  }

  void CRect::MoveBottom(int db) {
    fBottom += db;
    fHeight += db;
  }

  void CRect::Set(const CRect& source) {
    fLeft = source.fLeft;
    fTop = source.fTop;
    fWidth = source.fWidth;
    fHeight = source.fHeight;
    fRight = source.fRight;
    fBottom = source.fBottom;
  }

  void CRect::Set(int x, int y, int w, int h) {
    fLeft = x;
    fTop = y;
    fWidth = w;
    fHeight = h;
    fRight = x+w-1;
    fBottom = y+h-1;
  }

  void CRect::Move(int dx, int dy) {
    fLeft+=dx; fRight+=dx;
    fTop+=dy; fBottom+=dy;
  }

  void CRect::MoveTo(int x, int y) {
    fLeft = x;
    fTop = y;
    fRight = x+fWidth-1;
    fBottom = y+fHeight-1;
  }

  bool CRect::CheckSize(const CRect& source) {
    return ((fWidth ^ source.fWidth) | (fHeight ^ source.fHeight)) != 0;
  }

  bool CRect::CheckPosition(const CRect& source) {
    return ((fLeft ^ source.fLeft) | (fTop ^ source.fTop)) != 0;
  }

  void CRect::Resize(int w, int h) {
    fRight = fLeft+w-1; fWidth = w;
    fBottom = fTop+h-1; fHeight = h;
  }

  void CRect::Grow(const CRect& rect) {
    if (rect.fLeft < fLeft) fLeft = rect.fLeft;
    if (rect.fTop < fTop) fTop = rect.fTop;
    if (rect.fRight > fRight) fRight = rect.fRight;
    if (rect.fBottom > fBottom) fBottom = rect.fBottom;
    fWidth = fRight-fLeft+1;
    fHeight = fBottom-fTop+1;
  }

  void CRect::Intersect(const CRect& rect) {
    if (rect.fLeft > fLeft) fLeft = rect.fLeft;
    if (rect.fTop > fTop) fTop = rect.fTop;
    if (rect.fRight < fRight) fRight = rect.fRight;
    if (rect.fBottom < fBottom) fBottom = rect.fBottom;
    fWidth = fRight-fLeft+1;
    fHeight = fBottom-fTop+1;
  }

  void CRect::MoveIn(const CRect &rect) {
    if (rect.fLeft > fLeft) {
      fRight += (rect.fLeft - fLeft);
      if (fRight > rect.fRight) fRight = rect.fRight;
      fLeft = rect.fLeft;
      fWidth = fRight-fLeft+1;
    }
    if (rect.fTop > fTop) {
      fBottom += (rect.fTop - fTop);
      if (fBottom > rect.fBottom) fBottom = rect.fBottom;
      fTop = rect.fTop;
      fHeight = fBottom-fTop+1;
    }
    if (rect.fRight < fRight) {
      fLeft += (rect.fRight - fRight);
      if (fLeft < rect.fLeft) fLeft = rect.fLeft;
      fRight = rect.fRight;
      fWidth = fRight-fLeft+1;
    }
    if (rect.fBottom < fBottom) {
      fTop += (rect.fBottom - fBottom);
      if (fTop < rect.fTop) fTop = rect.fTop;
      fBottom = rect.fBottom;
      fHeight = fBottom-fTop+1;
    }
  }

  bool CRect::Collide(const CRect& rect) const {
    return ((fRight-rect.fLeft) | (rect.fRight-fLeft) | (fBottom-rect.fTop) | (rect.fBottom-fTop)) >=0;
  }

  void CRect::Center(const CRect ref, bool hz, bool vt) {
    if (hz) {
      int xref = (ref.fLeft + ref.fRight) >> 1;
      fRight = (fLeft = xref - (fWidth >> 1)) + fWidth - 1;
    }
    if (vt) {
      int yref = (ref.fTop + ref.fBottom) >> 1;
      fBottom = (fTop = yref - (fHeight >> 1)) + fHeight - 1;
    }
  }

  void CRect::Expand(int p) {
    fLeft -= p;
    fTop -= p;
    fRight += p;
    fBottom += p;
    fWidth += p<<1;
    fHeight += p<<1;
  }

  void CRect::Expand(int dx, int dy) {
    fLeft -= dx;
    fTop -= dy;
    fRight += dx;
    fBottom += dy;
    fWidth += dx<<1;
    fHeight += dy<<1;
  }

  void CRect::Contract(int p) {
    fLeft += p;
    fTop += p;
    fRight -= p;
    fBottom -= p;
    fWidth -= p<<1;
    fHeight -= p<<1;
  }

  void CRect::Contract(int dx, int dy) {
    fLeft += dx;
    fTop += dy;
    fRight -= dx;
    fBottom -= dy;
    fWidth -= dx<<1;
    fHeight -= dy<<1;
  }

  bool CRect::In(int x, int y) const {
    return (((fWidth | fHeight) > 0) && ((unsigned int)(x-fLeft) < (unsigned int)fWidth) && ((unsigned int)(y-fTop) < (unsigned int)fHeight));
  }
}