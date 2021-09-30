pkgname="sstring"
pkgver="12.1.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("f2e33da7599277054a8aafdc5fc5ba093e36365ccf6fd4f8d86d76675d8c8402c4f655f799a5cc05f9a851ebd562907756cc0294f97c54cab8c84d0c651d5a75" "db8cadb8d9fc987510a567b62467f12d3e8ad312e6788053015fc8565e6cfadbfcaa16e0b6ecd0750c29426893ee760dd86e7746087bacb3d612560974a5c438" "e0c577f40f6a0a6a9ec366443435be40f969c3de41401b696ca50e3d51597fac316e4e6e18dabc648039f26037a444db8c26388afafa0f01bea4ae34fbfe10f7")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
