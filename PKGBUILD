pkgname="vector"
pkgver="1.4.3"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("a261d32a2dccb9f97aad1f69473d007196a7ae743c7d4e689700223a194347fc4b719069a041b8fd6c560949a2e4eccbab8a11d574274c56993b9065a1348f33" "ebeab7336c83fdfc0406679ecebf303e9d616c2ea81d2dd2a850c4b30b3d60a3247c791657870338d3f02454bdb8756c65688ee14839b661be45ee50a0d0cbe7")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}