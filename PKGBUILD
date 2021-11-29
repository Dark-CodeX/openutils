pkgname="vector"
pkgver="22.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("6025ddb11b310d2e01293505c45cc78ea9ecebe340cfef865280d75975b1c2527297f11359c851df1cbd03d6991869b559858862a8083703623be16916e109f0" "cad8eaf8fc2e63f34eb979ffa2dbad9b8e4834edafeee2c16e6c89d28e1dbb147b3c794e9fc8cac5611ed104a4edfe529d4062f2fc204c9ce748bf1fe2625780")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}