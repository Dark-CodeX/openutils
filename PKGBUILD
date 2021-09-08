pkgname="sstring"
pkgver="4.9.0"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("6afcf9be6cd7c2974eb0136f62ef36593645dd64bcf3855aee81771d034d12f23afb87c09771d298e6850f270d6081449015c7410cab303821c2f0f12c7fc0a2" "d7c6990bbe18241582299c29602a7fbdddcccf1622c0825420295e30d36963c50d1af3e3a07c2279d0ce91d0314a587581a569f0486710d06edbabdf8916ba14")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
