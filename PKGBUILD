pkgname="openutils-sstring"
pkgver="1.5.6"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.hh")

sha512sums=(
  "0726a2be541b06ee8371517df74a9d6632c0d199256527e4a26fcf2687ded3e16809fbac1a995c739945160b15e074ba3cc3252e3812da2564fb8b702588e570"
  "67ab06b9d860ad59f02144fd901a4bd9fb008da824ffcdcb4d83afea9bb0f5baf6836e682fc8b1d7300cc40e5b4750c352acea445aaad40ac297644a5c266c77"
  "4ad0ce32c1cf1dad440524221bdfddc20072f03ddbd5c567ad25b41d6f165b40ed7a1e3f61c3e33bf79b106fb2a0743fd8b83bb1fa00882c3539830d7605a50f"
  "434a68df898c936c8d857249951e691332d72e5e9d0c893fa995a16d4b2a85d22e784929ec5fcf1eebded2864e28a569d2d288281c50642c69d6ca8dd26e8e5d"
  "5e3fb4554b97fe4db4da34c70a21baa09569aaed250fef78d42fcb42a7ac1fe6fd52f301488efd74ae70a3a2ccae6678ee2f79471ebbf60a879ddba15805c30e")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/openutils/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/openutils/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/openutils/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
  echo "Done!"
}
