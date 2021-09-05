pkgname="sstring"
pkgver="3.8.5"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("465826f96cffb359bbca5ed01494d91ab07c5686cfd23123a61ae51c25af29827a014d1c2015b987c5984a1331b52e6354c208894cade9e3c0fe2a25760f245f" "a5dbf61911cfd9cad100b3921098e295bc85d0f4e984da39d0646604cb0239386755d50ea2bbab2fe9cae9da4a1b88dde5cf21257f27dcbeeae752af5d7b32a7")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
