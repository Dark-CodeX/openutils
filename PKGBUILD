pkgname="sstring"
pkgver="7.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("9d411ac92380f7ad4ae52a92d18f7b144c15dcccd35f0a21c0dd693c160b58e39287624595efb2a1d40aff0d18769da5404b89255d2eafb106a10ce2f703470c" "ab7a04a546c91069fec3d731209802c18880d50f06e0af26662b5464d4f8f81bb2a8ce9607a325a1e827d96e77e588eaa451f9a141c1606c35e7995a6a60f76f" "4230de5772eea4720e02f9454515b0a15c7221456623ee6f7dbae2be3eb7862571ea31442307339d2093839d929eee9e1ab3843534482ae4da4e183ef5a0acf2")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
