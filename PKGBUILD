pkgname="vector"
pkgver="1.5.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("ae429d5f76dcac71527567f1ad4d6e301be57d6fe027ffbd4bd9c42c78bccbc4d6c905e112bb6c426564865f9cb394c304a86b9edf9ec527ca45f039dcfdb0e5" "8193c5082f49a3d70cbfbd41983d6c88359e06cf4148ea5a78f62aebda765c678960053d4e9caf7d963f2fdbeec43dd05de60c1573c1f273d3c72c0f00525a32")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}