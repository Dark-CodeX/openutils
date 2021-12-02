pkgname="vector"
pkgver="29.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("bac5274362e7c00023a4cd877efd2be98cfbbebba87340b2387c0cb6d8127eb079ca03658ea3e5b3929b219345ac8309b08ebe557aad0bd3540e50e1880b7965" "f490a2b096bc451e75b2096331777159e320b39b1faf07ba80cadd48bbfcccb6b9584dce0c1dbc98ef44e9a3e22d841c6df86561c146a036d074c8ae9c2660b6")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}