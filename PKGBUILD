pkgname="vector"
pkgver="27.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("2911df9d007f29e0a5feaed1f868946910466ed231108abefb245259ed327f0ac6004b5559a4211494e29e67a12ccb6881f6ace06e1efefcd9a78ce844b979f1" "6303d7cef5a50be133f6aa9c431a4294f8e5ad30096ed721dccbcafc4b0fd9449e4984cd694b1b93a8e06bc42c5cb581d9d5cd140e374dba9226b27d9221d90a")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}