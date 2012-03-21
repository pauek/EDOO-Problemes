
#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
   float _r, _g, _b;
public:
   Pixel();
   Pixel(const Pixel& P);
   Pixel(float r, float g, float b);

   float red()   const { return _r; }
   float green() const { return _g; }
   float blue()  const { return _b; }

   float luminancia() const;
   float saturacio()  const;
   Pixel mescla(const Pixel& altre) const;   
};

#endif
