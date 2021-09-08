pkgname="sstring"
pkgver="5.0.0"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("cb99e0cbd1f29b04d1a581e6e641648e42929249727dafd9f44398d72e768b248f36f59094e363fb6b44925e8b9a2a90b80b75df6e376fc26f232d0a0ec6faa4" "d7c6990bbe18241582299c29602a7fbdddcccf1622c0825420295e30d36963c50d1af3e3a07c2279d0ce91d0314a587581a569f0486710d06edbabdf8916ba14" "57bab041b11cdd0b9aa394d43d4b68f8ee085b1e897aaec25fc02a53663c89287f917e12394852e9bc1269815a7f72332f1ab4dd2d83827e3b9c074dd319dbbe")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
