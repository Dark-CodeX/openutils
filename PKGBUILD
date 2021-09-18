pkgname="sstring"
pkgver="8.1.5"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("f819404970ed2cc1aefd7617f90f679c6d32ec1db09ef1c5fdf21cb76e114514814b0b9db685496a046d15d8acd158018d22605a0ab173c3a9935a6887ba34e1" "95e6f1191f8fd02a5fa9367e18689747faa8f7f0b0b85c4b4e36e0ed3de9f5174b36f22436e84dacc4d7726b0ecce8efd30c7fa13ca25d2e1a656d3acaa51c34" "cdac239db7206a33c7ea68dc457e1e33ac8143103ab9e79b4e7a9f76717481bd24aabd7bbd7c12733b565405c8e19c6f2b72ddfbf4f154226a4e2707ac52222a")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
