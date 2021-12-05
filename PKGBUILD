pkgname="vector"
pkgver="1.4.3"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("a261d32a2dccb9f97aad1f69473d007196a7ae743c7d4e689700223a194347fc4b719069a041b8fd6c560949a2e4eccbab8a11d574274c56993b9065a1348f33" "017541da3d9e8d771fe5d41fb0b75df16a123993698836cd75ce03200126517f244ff31897e2fd0e21c12f497cd6d7981cd7036995598c1b811f735f20d72636")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}