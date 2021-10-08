pkgname="sstring"
pkgver="18.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("4b06c61cbc8c72c181ed2c64b2f6ba5f7f37a6994d0eb121e197272a3c79ddcf51a68c116ee9d8d008b5787696e44e9b3dcbfcb54219d2d3640459860bfb4ba5" "1c29131c72e1fce51b48d80d0e40f3797f0e86a2f9af5636f6a0980467a7d738e1ba9aa4851c0f4a4c29c9f03716fcfe82c9a556ec0662e518cf298c48a5ad1e" "0629679f12c7253b919bf83912b7da8af7a2f030f075fbcc54db830bbe77bbd5fcc5fd820aebe2235bc2d3e85b9fca0085f8f2475368535e19ba5a0c3adc6198")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
