pkgname="vector"
pkgver="21.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("e840f669c3e3f2dde3e07fc146fe07fd985b83a936abef26b1d53adba8323f6852946bec79c670b01a40fc272edd7d5c04fb14544629477d9b29343465290051" "1f2c5f68c0c0eb664eaca03a410f7089df4a535f3d77a4279465b8411faeb8081156cae6c42e301e301101b313c79be8397d83002f6f077cff0708c9c3f0a125")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}