pkgname="vector"
pkgver="1.5.3"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("b2f8b649d73ca6eb61e4ff3dc445575f89d9a96bb4b9b36e4b53dde884909763ee3c750187a6c71d569e8af6f82ec71827601f9d150b83dddaa09f2d39abbedd" "ddba6aa6d92f0f73eec727a792b122b0db948bbd3ea44574d11a1f47e74415c077648cbd561ee7f5310840895721371db34d1d4e76822a3059449456f5529862")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
  echo "Done!"
}