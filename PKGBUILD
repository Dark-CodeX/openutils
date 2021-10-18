pkgname="sstring"
pkgver="24.5.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("b8e09424258086fba70a0e0aeb69d3cf962d9029caa8ef3d5468f5c95c8456400b103e147b324ea439f5de687f30191b5592c72dd63e9f5541afda59d0dc29e6" "654b35af2c5e8de46a8eb9b685608a391d681e935f2320d87a32f3e60725caa643011e7d66fb5d91ad2ad128861289a210b9d594515c01a8a3c0e235bf20e32d" "aa5b701a598ff0d9669f167455a6501d498df08a00f7a91029e6c8acbf0a7c905422c28eb8580ffa4e1864f925316581fc2353bfd38eb8d185b638415bb58269")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
