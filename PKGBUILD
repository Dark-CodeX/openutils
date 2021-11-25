pkgname="sstring"
pkgver="49.0.0"
pkgrel="7"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.hh")

sha512sums=(
  "71a8462439f7e3cc95cb68ae1ab25926bc9e98476ffdfd020558642de0323d3f6f1bb71c75febcf763aefc8245bda9c231bf6f875aef3eab561b0c237fece27d"
  "c8de1f78354273b49581dae833001ce9ff69a0a2a144efb41b8ca513b874c85ec7f2c8a6317153354f0b06d3dedf718d0f97697dbe8e45793db5b20ec2fa6147"
  "ff8aec84b0c9345083f59fcdcee5b7fdbf798efbaec25288a83350f913af4d73c3cf49003d4597383dd7534d5f575f3aa85b16198d88f011e3903857a669f0ec"
  "d56ddb73fdbdae8d0cee9b5e3e7c748fc539d4eea9f092d51848efd2a9e64f30a837c043fefd9b91cce81ff1d5bac2d7681bb8d0379ff0f58c51e770ecedb2a7"
  "32501876df4644910ff951cfcef1c0b9ec550767f8d516347bad8de8df0ceb94c809a97e23ae3d9a4c07801aa4d5282935db4b56b60bb41b5506c331bd18a255")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/sstring/sstring.hh"
  echo "Done!"
}
