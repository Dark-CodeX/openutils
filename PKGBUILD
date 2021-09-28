pkgname="sstring"
pkgver="12.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("376be14e3d40a08179c06702188ccc20f2152c6e357c055f3f2f11095852ffed2e5a8815a262b9c722473070ef7c7a4fb646cc55e0b99cae3c0e93656967ce9f" "de4ba2ba80130e9a76a34a4741f1b15c4502f7e73fd3d4669df5110bd5c6fac13a408fb854477c62c54f4e9d3064c2aef2afc937ade9ce8aadd08abe59a680bf" "e3863c6ef4c50ad57b996fb4a320bbd9668f384d68af31c972a6427b5cb00f8208d9fd6d7ffd3c4c03ea357faf4e0d7e95e199934d64499cf0f0361dc85cfed5")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
