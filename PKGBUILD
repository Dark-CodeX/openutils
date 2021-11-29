pkgname="vector"
pkgver="21.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("e840f669c3e3f2dde3e07fc146fe07fd985b83a936abef26b1d53adba8323f6852946bec79c670b01a40fc272edd7d5c04fb14544629477d9b29343465290051" "2189c7b429a409f0aafa4dbbd7846ca06e3ea59617626b0489c8984783a13f34ee24975499c28b275bdb3559a047aeb02a98690cdb644e8b0b4cb0eb5ba75b58")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}