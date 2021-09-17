pkgname="sstring"
pkgver="8.0.0"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("620acdbbf0f4264daaea555985db0ff6a40682f0e146e6942732b08634d3ab880eb0dab60bb80163e4d4a49b31ab2a44e106691bcde1a12a2e174958f0e3ae29" "5dbe812a33a3ac918e52d578b9dd4ae81199647d16ffa0ae8da890fe28a340177eaa98f304093adb7a4791e7ca26b8020022685fa40f7cb8597638ce8c141e08" "9b0bd7b2293d38271169f37cfa0ec2f6eee36a15aa2ccfa9099d36e84908cfa99669b3940a3fc396efe713f6025366c2ae038ad7e98dc2ede001f4ec5d535c56")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
