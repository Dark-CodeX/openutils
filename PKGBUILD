pkgname="sstring"
pkgver="15.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("1053f7b9c605b878631266b1c5804bf50e8172614625fac1cfb9e3ab8895a27867f11003bc5edd97da44c0665b2d8cc4fa3f850a7176d95b68c84868a9b94dc2" "cbe56370038a48fa60d288e839627fc7e8b49a7bdfa57ac9b2db9d1b400dc0230ec0a85f2435879fd203c1e1970360ae2588170a75a17a807d6602710a7dfa52" "54f72e144e8f9b3ebb847788f711f70e24dde24f45d58ef0cfc98203d71b2e845206d49df5307456b5b3b9108c2a71e4a5236d38596afe8680bc22ac7b087579")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
