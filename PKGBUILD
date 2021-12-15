pkgname="openutils-vector"
pkgver="1.5.3"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("b2f8b649d73ca6eb61e4ff3dc445575f89d9a96bb4b9b36e4b53dde884909763ee3c750187a6c71d569e8af6f82ec71827601f9d150b83dddaa09f2d39abbedd" "68c1c9a67d1ecdb8fece516fd71c3e058b8e87fcad5c984607349b22f623d24a8967120992a89eeb37d87e99721355b8867986d253fd80a9abe9c288e8b9cbb5")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
  echo "Done!"
}