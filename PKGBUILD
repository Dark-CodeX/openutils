pkgname="openutils-vector"
pkgver="1.5.5"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("a94fdfc573118e762d6eaff1f940ea2305c923c8ff9bc48dd3353af1f14338d18d7ab0478a69ed71b663d5c1345478d9f3151f16a8fccd17e0286eb5798c02dd" "d63eabe6b7d43f99d2301c26e862920b934d817eecae36af99c3d9fb9a0491189d6d89c1c2a34c32eef1246e50fbee48d7bc98d7bcd947b755d580d9f3cd089c")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
  echo "Done!"
}