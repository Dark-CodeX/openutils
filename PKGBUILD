pkgname="sstring"
pkgver="15.0.1"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("796bb7acb208b874844953c13c673fd4999672876bc3e95b786ca382a916fcb071d704a68ce4752fccedc754205818f7f463980e3d4b2500845f05c559e1c506" "35b69c7f55ecbc889609e5dc40251e2bb6e9f125a27279997b127479dfbb6b5335de7fe189b542ec18736cd1392ea5fcac797be78992d1a1c4a901fb2114e084" "54f72e144e8f9b3ebb847788f711f70e24dde24f45d58ef0cfc98203d71b2e845206d49df5307456b5b3b9108c2a71e4a5236d38596afe8680bc22ac7b087579")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
